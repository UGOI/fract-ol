NAME	:= fract_ol
CFLAGS	:= -Wextra -Wall -Werror -fsanitize=address
LIBMLX	:= ./lib/MLX42
LIBFT	:= ./lib/libft
BREW = $(shell which brew | rev | cut -c 9- | rev)
VERSION = $(shell ls $(BREW)/Cellar/glfw/)

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/libmlx42.a -lglfw -L $(BREW)/Cellar/glfw/$(VERSION)/lib/
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: libmlx libft $(NAME)

libmlx:
	@$(MAKE) -C $(LIBMLX)

libft:
	@$(MAKE) -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) -L ${LIBFT} -lft -fsanitize=address -g

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBMLX) clean
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBMLX) fclean
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, libft
