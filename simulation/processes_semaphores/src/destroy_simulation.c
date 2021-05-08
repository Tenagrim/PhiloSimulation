#include <philo.h>

static void		destroy_threads(t_simulation *sim)
{
	unsigned int i;

	i = 0;
	while (i < sim->settings.phil_count)
	{
		unlock_f(sim->all_eated_up_trigger);
		kill(sim->pids[i], 9);
		i++;
	}
	free(sim->threads);
	free(sim->pids);
}

void			destroy_simulation(t_simulation *sim)
{
	usleep(1000);
	destroy_threads(sim);
	destroy_forks(sim);
	destroy_philos(sim);
	sem_unlink(SEM_TRIG);
	sem_unlink(SEM_TIME);
	sem_unlink(SEM_OUT);
	sem_unlink(SEM_EAT_UP);
	sem_close(sim->get_time_mut);
	sem_close(sim->out_mutex);
	sem_close(sim->death_trigger);
	sem_close(sim->all_eated_up_trigger);
}
