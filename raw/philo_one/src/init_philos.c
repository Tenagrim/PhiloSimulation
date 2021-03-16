/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 23:06:04 by gshona            #+#    #+#             */
/*   Updated: 2021/03/16 15:03:48 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void			init_philos(t_simulation *sim)
{
	unsigned int i;
	unsigned int c;

	c = sim->settings.phil_count;
	i = 0;
	sim->philos = (t_philo*)ft_malloc(sizeof(t_philo) * c);
	while (i < c)
	{
		sim->philos[i].num = i + 1;
		sim->philos[i].times_eated = 0;
		sim->philos[i].state = ST_THINKING;
		sim->philos[i].start_time = &(sim->start_time);
		sim->philos[i].out_mutex = &(sim->out_mutex);
		sim->philos[i].death_trigger = &(sim->death_trigger);
		sim->philos[i].l_fork = &(sim->forks[circuled_num(i - 1, c)]);
		sim->philos[i].r_fork = &(sim->forks[i]);
		sim->philos[i].get_time_mut = &(sim->get_time_mut);
		sim->philos[i].settings = &(sim->settings);
		//get_timestamp(&(sim->philos[i].last_eat), &(sim->get_time_mut));
		sim->philos[i].l_philo = &sim->philos[circuled_num(i - 1, c)];
		sim->philos[i].r_philo = &sim->philos[circuled_num(i + 1, c)];
		i++;
	}
}
