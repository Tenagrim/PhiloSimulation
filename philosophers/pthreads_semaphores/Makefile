NAME=simulation
SRC_DIR = src/
OBJ_DIR = src/
SRC_FILES = check_input.c \
			circuled_num.c \
			destroy_forks.c \
			destroy_philos.c \
			destroy_simulation.c \
			die.c \
			display_message.c \
			display_philo.c \
			drop_forks.c \
			eat.c \
			err_exit.c \
			ft_atoi.c \
			ft_malloc.c \
			ft_putunbr_fd.c \
			ft_sem_open.c \
			ft_strcmp.c \
			ft_strlen.c \
			get_sim_settings.c \
			get_time_diff.c \
			get_time_udiff.c \
			get_timestamp.c \
			init_forks.c \
			init_philos.c \
			init_simulation.c \
			lock_f.c \
			main.c \
			philo_life.c \
			print_settings.c \
			run_simulation.c \
			sleep.c \
			start_philos.c \
			take_forks.c \
			unleash_the_kraken.c \
			unlock_f.c \
			usleep_from.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))
H=includes/philo.h
CC= gcc
FLAGS= -g -Iincludes  -Wall -Wextra  -Werror

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

