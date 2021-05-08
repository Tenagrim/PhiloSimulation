#include <philo.h>

void			init_forks(t_simulation *sim)
{
	unsigned int i;

	sim->forks = ft_malloc(sizeof(t_mutex) * sim->settings.phil_count);
	i = 0;
	while (i < sim->settings.phil_count)
	{
		pthread_mutex_init(&(sim->forks[i]), NULL);
		i++;
	}
}
