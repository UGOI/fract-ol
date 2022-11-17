NAME	:= fract_ol
CFLAGS	:=
CFLAGS2	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./lib/MLX42
BREW = $(shell which brew | rev | cut -c 9- | rev)
VERSION = $(shell ls $(BREW)/Cellar/glfw/)

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/libmlx42.a -lglfw -L $(BREW)/Cellar/glfw/$(VERSION)/lib/
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@$(MAKE) -C $(LIBMLX)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBMLX) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBMLX) fclean

re: fclean all

.PHONY: all, clean, fclean, re, libmlx
