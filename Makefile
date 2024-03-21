NAME	=	push_swap

SRCS = ft_check_alpha.c \
	ft_node.c \
	ft_rr.c \
	ft_sort_five.c \
	ft_split.c \
	ft_utils.c \
	ft_utilssec.c \
	ft_uutils.c \
	ft_mem.c \
	ft_pab.c \
	ft_rrr.c \
	ft_sort_small.c \
	ft_ss.c \
	ft_utilsfour.c \
	ft_utilsthree.c \
	push_swap.c

OBJS	= ${SRCS:.c=.o}


CC =	gcc

CFLAGS	=	-Wall -Wextra -Werror

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:  ${NAME}

$(NAME): ${OBJS}
		$(CC) $(CFLAGS) ${OBJS} -o $(NAME)


clean:
		rm -f ${OBJS}

fclean:	clean
		rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re