NAME := push_swap

SRC := src/checkargs.c \
       src/freestack.c \
       src/move_stack.c \
       src/move_stack_tini.c \
       src/push_swap.c \
       src/push_swap_utils.c \
       src/sort_stack.c \
       src/t_ilist_utils.c

INCLUDE		=	-I.

LIBFT_DIR = libft

CC := cc

OBJS		=	$(patsubst %.c,%.o,$(SRC))

CFLAGS := -Wall -Werror -Wextra 

all: ${LIBFT_DIR}/libft.a   ${NAME}

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

%.o:		%.c
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ 

${NAME}: ${OBJS} 
	${CC} ${CFLAGS} ${LIB} -o ${NAME} ${OBJS} -L./libft -lft

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean ${NAME}

.PHONY: all clean fclean re 
