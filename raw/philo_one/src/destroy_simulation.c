/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:40:52 by gshona            #+#    #+#             */
/*   Updated: 2021/03/19 14:44:14 by gshona           ###   ########.fr       */
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
	pthread_mutex_destroy(&(sim->death_trigger));
	pthread_mutex_destroy(&(sim->get_time_mut));
	pthread_mutex_destroy(&(sim->out_mutex));
}
