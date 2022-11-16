CFLAGS	:= -Wextra -Wall -Werror
LIBMLX	:= ../lib/MLX42
BREW 	= $(shell which brew | rev | cut -c 9- | rev)
VERSION = $(shell ls $(BREW)/Cellar/glfw/)

HEADERS			:= -I ../include -I $(LIBMLX)/include
LIBS			:= $(LIBMLX)/libmlx42.a -lglfw -L $(BREW)/Cellar/glfw/$(VERSION)/lib/
SRCS_COMPLEX	:= $(shell find ./src -iname "*.c") ../src/complex.c
OBJS_COMPLEX	:= ${SRCS_COMPLEX:.c=.o}
OBJ_PATH	= ./obj/
SRC_PATH	= ./src/

all: libmlx complex

libmlx:
	@$(MAKE) -C $(LIBMLX)

${OBJ_PATH}%.o: ${SRC_PATH}%.c
		@mkdir -p $(OBJ_PATH)
		@cc ${CFLAGS} -c $< -o ${OBJ_PATH}${<:.c=.o}

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
