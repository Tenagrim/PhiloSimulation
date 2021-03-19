/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:55:53 by gshona            #+#    #+#             */
/*   Updated: 2021/03/19 12:55:39 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void		create(t_simulation *sim, int i)
{
	int r;
	r  = pthread_create(&sim->threads[i], NULL, philo_life,
			(void*)(sim->philos + i));
	if (r != 0)
		err_exit("failed to start tread\n", 3);
	//pthread_detach(sim->threads[i]); <---------------------- !!!!!
}

void			start_philos(t_simulation *sim)
{
	unsigned int i;

	i = 0;
	while (i < sim->settings.phil_count)
	{
		//printf("start process [%d]\n", i);
		create(sim, i);
		usleep(P_LAUNCH_RANGE);
		i += 2;
	}
	usleep(sim->settings.time_to_eat * 1000);
	i = 1;
	while (i < sim->settings.phil_count)
	{
		//printf("start process [%d]\n", i);
		create(sim, i);
		i += 2;
		usleep(P_LAUNCH_RANGE);
	}
}
