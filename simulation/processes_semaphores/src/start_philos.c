#include <philo.h>

static void		create(t_simulation *sim, int i)
{
	int r;

	r = fork();
	if (r == -1)
		err_exit("failed to fork\n", 3);
	else if (r == 0)
	{
		lock_f(sim->all_eated_up_trigger);
		unleash_the_kraken(sim);
		philo_life((void*)(sim->philos + i));
	}
	else
		sim->pids[i] = r;
}

void			start_philos(t_simulation *sim)
{
	unsigned int i;

	i = 0;
	sim->cur_philo = 0;
	while (i < sim->settings.phil_count)
	{
		sim->cur_philo = i;
		create(sim, i);
		usleep(P_LAUNCH_RANGE);
		i += 2;
	}
	usleep(sim->settings.time_to_eat * 1000);
	i = 1;
	while (i < sim->settings.phil_count)
	{
		sim->cur_philo = i;
		create(sim, i);
		i += 2;
		usleep(P_LAUNCH_RANGE);
	}
}
