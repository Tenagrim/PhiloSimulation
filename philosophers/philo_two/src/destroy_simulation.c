/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:40:52 by gshona            #+#    #+#             */
/*   Updated: 2021/03/19 19:34:13 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void		destroy_threads(t_simulation *sim)
{
	free(sim->threads);
}

void			destroy_simulation(t_simulation *sim)
{
	usleep(1000);
	destroy_forks(sim);
	destroy_philos(sim);
	destroy_threads(sim);
	sem_unlink(SEM_TRIG);
	sem_unlink(SEM_TIME);
	sem_unlink(SEM_OUT);
	sem_close(sim->get_time_mut);
	sem_close(sim->out_mutex);
	sem_close(sim->death_trigger);
}
