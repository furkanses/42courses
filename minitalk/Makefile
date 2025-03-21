FLAGS = -Wall -Wextra -Werror
CC = cc
NAME = minitalk
NAME_BONUS = minitalk_bonus

CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

CLIENT_SRC = client.c
SERVER_SRC = server.c
CLIENT_BONUS_SRC = client_bonus.c
SERVER_BONUS_SRC = server_bonus.c

CLIENT_OBJS = $(CLIENT_SRC:.c=.o)
SERVER_OBJS = $(SERVER_SRC:.c=.o)
CLIENT_BONUS_OBJS = $(CLIENT_BONUS_SRC:.c=.o)
SERVER_BONUS_OBJS = $(SERVER_BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(FLAGS) $(CLIENT_OBJS) -o $(CLIENT)

$(SERVER): $(SERVER_OBJS)
	$(CC) $(FLAGS) $(SERVER_OBJS) -o $(SERVER)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS): $(CLIENT_BONUS_OBJS)
	$(CC) $(FLAGS) $(CLIENT_BONUS_OBJS) -o $(CLIENT_BONUS)

$(SERVER_BONUS): $(SERVER_BONUS_OBJS)
	$(CC) $(FLAGS) $(SERVER_BONUS_OBJS) -o $(SERVER_BONUS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(CLIENT_OBJS) $(SERVER_OBJS) $(CLIENT_BONUS_OBJS) $(SERVER_BONUS_OBJS)

fclean: clean
	rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
