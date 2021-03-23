/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:43:05 by gshona            #+#    #+#             */
/*   Updated: 2021/03/19 20:40:00 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void		init_threads(t_simulation *sim)
{
	sim->threads = ft_malloc(sizeof(pthread_t) * sim->settings.phil_count);
	sim->pids = ft_malloc(sizeof(int) * sim->settings.phil_count);
}

void			init_simulation(t_simulation *sim)
{
	sim->death_trigger = ft_sem_open(SEM_TRIG, 1);
	sim->out_mutex = ft_sem_open(SEM_OUT, 1);
	sim->get_time_mut = ft_sem_open(SEM_TIME, 1);
	sim->all_eated_up_trigger = ft_sem_open(SEM_TIME, sim->settings.phil_count);
	init_forks(sim);
	init_philos(sim);
	init_threads(sim);
}
