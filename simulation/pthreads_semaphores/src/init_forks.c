#include <philo.h>

void			init_forks(t_simulation *sim)
{
	sim->forks = ft_sem_open(SEM_FORKS, sim->settings.phil_count);
}
