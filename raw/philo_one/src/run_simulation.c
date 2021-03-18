/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_run.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:48:47 by gshona            #+#    #+#             */
/*   Updated: 2021/03/18 14:54:09 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void			run_simulation(t_simulation *sim)
{
	gettimeofday(&(sim->start_time), NULL);
	lock_f(&(sim->death_trigger));
	start_philos(sim);
	lock_f(&(sim->death_trigger));
}
