NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_printf.c \
		ft_hexadecimal.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_adress.c \
		ft_putnbr_unsigned.c \

OBJS = $(SRCS:.c=.o)





all:$(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
