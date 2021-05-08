#include <philo.h>

void			destroy_forks(t_simulation *sim)
{
	sem_unlink(SEM_FORKS);
	sem_close(sim->forks);
}
