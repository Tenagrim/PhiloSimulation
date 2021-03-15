/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 19:57:35 by gshona            #+#    #+#             */
/*   Updated: 2021/03/15 23:14:32 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# define ST_THINKING	0
# define ST_EATING		1
# define ST_SLEEPING	2
# define ST_DEAD		3

typedef struct timeval t_timeval;
typedef struct pthread_mutex_t t_mutex;

typedef struct	s_sim_settings
{
	unsigned long	phil_count;
	unsigned long	time_to_die;
	unsigned long	time_to_sleep;
	unsigned long	time_to_eat;
	int				times_must_eat;

}				t_sim_settings;

typedef struct
{
	unsigned int	num;
	int				state;
	t_timeval		last_eat;
	t_timeval		*start_time;
	t_mutex			*out_mutex;
}				t_philo;

typedef struct
{
	t_philo			*philos;
	t_timeval		start_time;
	pthread_mutex_t	out_mutex;
	t_sim_settings	settings;
}				t_simulation;

typedef struct
{
	t_simulation	*sim;
	int				cur;
}				t_life_args;

void			get_sim_settings(t_sim_settings *setts, char **av);
void			err_exit(char *str, int code);
int				ft_strlen(char *str);
void			check_input(int ac, char **av);
void			print_settings(t_sim_settings *setts);
int				ft_atoi(char *str);
int				main_loop(t_simulation *sim);
unsigned long	get_time_diff(t_timeval *t1, t_timeval *t2);
unsigned long	get_time_udiff(t_timeval *t1, t_timeval *t2);
void			*philo_life(void *args);
void			display_philo(t_philo *philo, t_mutex *out_mutex);
t_life_args		*new_life_args(t_simulation *sim, int cur);
void			init_philos(t_simulation *sim);
void			destroy_philos(t_simulation *sim);
#endif
