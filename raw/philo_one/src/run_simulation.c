/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_run.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:48:47 by gshona            #+#    #+#             */
/*   Updated: 2021/03/16 13:57:04 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void			run_simulation(t_simulation *sim)
{
	get_timestamp(&(sim->start_time), &(sim->get_time_mut));
	lock_f(&(sim->death_trigger));
	start_philos(sim);
	lock_f(&(sim->death_trigger));
}
