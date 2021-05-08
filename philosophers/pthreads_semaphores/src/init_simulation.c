#include <philo.h>

static void		init_threads(t_simulation *sim)
{
	sim->threads = ft_malloc(sizeof(pthread_t) * sim->settings.phil_count);
}

void			init_simulation(t_simulation *sim)
{
	sim->death_trigger = ft_sem_open(SEM_TRIG, 1);
	sim->out_mutex = ft_sem_open(SEM_OUT, 1);
	sim->get_time_mut = ft_sem_open(SEM_TIME, 1);
	init_forks(sim);
	init_philos(sim);
	init_threads(sim);
}
