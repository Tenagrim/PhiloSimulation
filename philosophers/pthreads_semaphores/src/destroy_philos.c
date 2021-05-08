#include <philo.h>

void			destroy_philos(t_simulation *sim)
{
	free(sim->philos);
}
