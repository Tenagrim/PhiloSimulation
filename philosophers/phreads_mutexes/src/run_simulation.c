#include <philo.h>

void			run_simulation(t_simulation *sim)
{
	get_timestamp(&(sim->start_time), &(sim->get_time_mut));
	lock_f(&(sim->death_trigger));
	start_philos(sim);
	unleash_the_kraken(sim);
	lock_f(&(sim->death_trigger));
}
