NAME		=	push_swap

NAME_BONUS =    checker

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	push_swap.c						\
				check_args.c					\
				ft_split.c						\
				push.c							\
				rotate.c						\
				rrotate.c						\
				swap.c 							\
				utils_a.c						\
				utils_b.c						\
				utils_first.c					\
				utils_second.c					\
				ways.c							\
				get_next_line/get_next_line.c	\
				get_next_line/get_next_line_utils.c

SRCS_BONUS = 	checker_bonus.c					\
				check_args.c					\
				ft_split.c						\
				push.c							\
				rotate.c						\
				rrotate.c						\
				swap.c 							\
				utils_a.c						\
				utils_b.c						\
				utils_first.c					\
				utils_second.c					\
				ways.c							\
				get_next_line/get_next_line.c	\
				get_next_line/get_next_line_utils.c			


OBJS		= 	${SRCS:.c=.o}

OBJS_BONUS  =   ${SRCS_BONUS:.c=.o}

all:		${NAME}

bonus :		$(NAME_BONUS) 

${NAME}:	${OBJS}
			${CC} ${CFLAGS} $^ -o $@

${NAME_BONUS}:	${OBJS_BONUS}
			${CC} ${CFLAGS} $^ -o $@

clean:
			rm -f ${OBJS}
			rm -f ${OBJS_BONUS}

fclean:		clean
			rm -f ${NAME}
			rm -f $(NAME_BONUS)

re:			fclean all

.PHONY:		all clean fclean re
