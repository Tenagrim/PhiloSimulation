/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:34:35 by gshona            #+#    #+#             */
/*   Updated: 2021/03/16 11:49:21 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void			init_forks(t_simulation *sim)
{
	unsigned int i;

	sim->forks = ft_malloc(sizeof(t_mutex) * sim->settings.phil_count);
	i = 0;
	while (i < sim->settings.phil_count)
	{
		pthread_mutex_init(&(sim->forks[i]), NULL);
		i++;
	}
}
