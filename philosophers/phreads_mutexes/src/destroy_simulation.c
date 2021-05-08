#include <philo.h>

static void		destroy_threads(t_simulation *sim)
{
	free(sim->threads);
}

void			destroy_simulation(t_simulation *sim)
{
	usleep(1000);
	destroy_forks(sim);
	destroy_philos(sim);
	destroy_threads(sim);
	pthread_mutex_destroy(&(sim->death_trigger));
	pthread_mutex_destroy(&(sim->get_time_mut));
	pthread_mutex_destroy(&(sim->out_mutex));
}
