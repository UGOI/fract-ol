CFLAGS	:= -Wextra -Wall -Werror
LIBMLX	:= ../lib/MLX42
BREW 	= $(shell which brew | rev | cut -c 9- | rev)
VERSION = $(shell ls $(BREW)/Cellar/glfw/)

HEADERS			:= -I ../include -I $(LIBMLX)/include
LIBS			:= $(LIBMLX)/libmlx42.a -lglfw -L $(BREW)/Cellar/glfw/$(VERSION)/lib/
SRCS_COMPLEX	:= $(shell find ./src -iname "*.c") ../src/complex.c ../src/fractals.c ../src/colors.c ../src/fractal_utils.c ../src/zoom.c
OBJS_COMPLEX	:= ${SRCS_COMPLEX:.c=.o}
OBJ_PATH	= ./obj/
SRC_PATH	= ./src/

all: libmlx complex

libmlx:
	@$(MAKE) -C $(LIBMLX)

${OBJ_PATH}%.o: ${SRC_PATH}%.c
		@mkdir -p $(OBJ_PATH)
		@cc ${CFLAGS} -c $<-o ${OBJ_PATH}${<:.c=.o} $(HEADERS)

complex: ${OBJS_COMPLEX}
	@$(CC) $(OBJS_COMPLEX) $(LIBS) $(HEADERS) -o complex

clean:
	@rm -rf obj
	@$(MAKE) -C $(LIBMLX) clean

fclean: clean
	@rm -f complex
	@$(MAKE) -C $(LIBMLX) fclean

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, complex

# NAME	:= fract_ol
# CFLAGS	:=
# CFLAGS2	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g -fsanitize=address
# LIBMLX	:= ../lib/MLX42
# BREW = $(shell which brew | rev | cut -c 9- | rev)
# VERSION = $(shell ls $(BREW)/Cellar/glfw/)

# HEADERS	:= -I ../include -I $(LIBMLX)/include
# LIBS	:= $(LIBMLX)/libmlx42.a -lglfw -L $(BREW)/Cellar/glfw/$(VERSION)/lib/
# SRCS	:= $(shell find ./src -iname "*.c")
# OBJS	:= ${SRCS:.c=.o}

# all: libmlx $(NAME)

# libmlx:
# 	@$(MAKE) -C $(LIBMLX)

# %.o: %.c
# 	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

# $(NAME): $(OBJS)
# 	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

# clean:
# 	@rm -f $(OBJS)
# 	@$(MAKE) -C $(LIBMLX) clean

# fclean: clean
# 	@rm -f $(NAME)
# 	@$(MAKE) -C $(LIBMLX) fclean

# re: fclean all

# .PHONY: all, clean, fclean, re, libmlx
