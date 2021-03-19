NAME=philo_three
SRC_DIR = src/
OBJ_DIR = src/
SRC_FILES = $(shell ls -1 src | grep "\.c")
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))
H=includes/philo.h
CC= gcc
FLAGS= -g -Iincludes  -Wall -Wextra # -Werror 

all: $(NAME)

%.o: %.c $(H)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ) $(H)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ);

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME);

re: fclean all

