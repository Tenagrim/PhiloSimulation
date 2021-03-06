#include <philo.h>

static void		init_threads(t_simulation *sim)
{
	sim->threads = ft_malloc(sizeof(pthread_t) * sim->settings.phil_count);
}

void			init_simulation(t_simulation *sim)
{
	pthread_mutex_init(&(sim->out_mutex), NULL);
	pthread_mutex_init(&(sim->death_trigger), NULL);
	pthread_mutex_init(&(sim->get_time_mut), NULL);
	init_forks(sim);
	init_philos(sim);
	init_threads(sim);
}
