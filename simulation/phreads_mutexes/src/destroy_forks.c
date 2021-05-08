#include <philo.h>

void			destroy_forks(t_simulation *sim)
{
	unsigned int i;

	i = 0;
	while (i < sim->settings.phil_count)
	{
		pthread_mutex_destroy(&(sim->forks[i]));
		i++;
	}
	free(sim->forks);
}
