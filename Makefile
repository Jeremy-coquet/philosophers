NAME = philo
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pthread -O2
# SANITIZE =  -fsanitize=thread
RM = rm -f
SRC_DIR = src/
OBJ_DIR = obj/

SRCS =	main.c \
		actions.c \
		error.c \
		free.c \
		init.c \
		parsing.c \
		philo.c \
		routine.c \
		utils.c \


OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SANITIZE) -o $(NAME) $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(SANITIZE) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
