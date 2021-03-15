NAME=philo_one
SRC=src/*.c
H=philo.h
CC= gcc
OBJ=$(SRC:.c=.o)
FLAGS= -Iincludes  -Wall -Wextra # -Werror 

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HPP)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ);

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME);

re: fclean all


