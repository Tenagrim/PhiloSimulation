#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# define ST_THINKING	0
# define ST_EATING		1
# define ST_SLEEPING	2
# define ST_DEAD		3
# define ST_TAKE_FORK	5
# define P_LAUNCH_RANGE 0
# define P_WAIT_FORK_STEP 10
# define P_USLEEP_STEP 150
# define P_KRAKEN_S_LUNCH 150
# define P_WT 3
# define F_DEBUG 1
# define F_ENDED 2
# define SEM_FORKS "forks_sem"
# define SEM_OUT "out_sem"
# define SEM_TRIG "trigger_sem"
# define SEM_TIME "time_sem"

typedef struct timeval	t_timeval;
typedef sem_t			t_mutex;

typedef struct			s_sim_settings
{
	unsigned long		phil_count;
	unsigned long		time_to_die;
	unsigned long		time_to_sleep;
	unsigned long		time_to_eat;
	unsigned int		times_must_eat;
	int					flags;
	unsigned int		deaths;
	unsigned long int	starving;
	unsigned long int	fastest;
}						t_sim_settings;

typedef struct			s_philo
{
	unsigned int		num;
	int					state;
	unsigned int		times_eated;
	t_timeval			last_eat;
	t_timeval			*start_time;
	t_mutex				*out_mutex;
	t_mutex				*get_time_mut;
	t_mutex				*death_trigger;
	t_mutex				*l_fork;
	t_mutex				*r_fork;
	t_sim_settings		*settings;
	struct s_philo		*l_philo;
	struct s_philo		*r_philo;
}						t_philo;

typedef struct			s_simulation
{
	t_philo				*philos;
	pthread_t			*threads;
	pthread_t			kraken;
	t_timeval			start_time;
	t_mutex				*forks;
	t_mutex				*out_mutex;
	t_mutex				*get_time_mut;
	t_mutex				*death_trigger;
	t_sim_settings		settings;
}						t_simulation;

void					get_sim_settings(t_sim_settings *setts, char **av);
void					err_exit(char *str, int code);
int						ft_strlen(char *str);
void					check_input(int ac, char **av);
void					print_settings(t_sim_settings *setts);
int						ft_atoi(char *str);
unsigned long			get_time_diff(t_timeval *t1, t_timeval *t2);
unsigned long			get_time_udiff(t_timeval *t1, t_timeval *t2);
void					*philo_life(void *args);
void					display_philo(t_philo *philo);
void					init_philos(t_simulation *sim);
void					destroy_philos(t_simulation *sim);
void					init_simulation(t_simulation *sim);
void					destroy_simulation(t_simulation *sim);
void					run_simulation(t_simulation *sim);
int						lock_f(t_mutex *mut);
int						unlock_f(t_mutex *mut);
void					start_philos(t_simulation *sim);
void					*ft_malloc(unsigned int size);
void					init_forks(t_simulation *sim);
void					destroy_forks(t_simulation *sim);
int						circuled_num(int value, int size);
void					display_message(t_philo *p, int state);
void					take_forks(t_philo *philo);
void					drop_forks(t_philo *philo);
void					eat(t_philo *philo);
void					sleep_(t_philo *philo);
void					usleep_from(t_timeval *start,
		unsigned long millis, t_mutex *mut);
void					die(t_philo *philo);
void					display_philo(t_philo *philo);
void					ft_putunbr_fd(int fd, long unsigned int num);
int						ft_strcmp(const char *s1, const char *s2);
int						get_timestamp(t_timeval *tv, t_mutex *mut);
void					unleash_the_kraken(t_simulation *sim);
t_mutex					*ft_sem_open(const char *name, int value);
#endif
