/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_run.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:48:47 by gshona            #+#    #+#             */
/*   Updated: 2021/03/19 21:42:04 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void				*waiting(void *arg)
{
	t_simulation	*sim;
	unsigned int	i;

	sim = (t_simulation*)arg;
	i = 0;
	usleep(sim->settings.time_to_eat * 1500);
	while (i < sim->settings.phil_count)
	{
		lock_f(sim->all_eated_up_trigger);
		i++;
	}
	unlock_f(sim->death_trigger);
	return (NULL);
}

static void			wait_for_full_eat_up(t_simulation *sim)
{
	pthread_t	waiter;
	int			r;

	r = pthread_create(&waiter, NULL,
			waiting, (void*)sim);
	if (r != 0)
		err_exit("failed to unleash the kraken\n", 3);
	pthread_detach(sim->threads[sim->cur_philo]);
}

void				run_simulation(t_simulation *sim)
{
	get_timestamp(&(sim->start_time), sim->get_time_mut);
	lock_f(sim->death_trigger);
	start_philos(sim);
	wait_for_full_eat_up(sim);
	lock_f(sim->death_trigger);
}
