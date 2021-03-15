/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 23:06:04 by gshona            #+#    #+#             */
/*   Updated: 2021/03/15 23:17:31 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void		*ft_malloc(unsigned int size)
{
	void	*res;

	res = malloc(size);
	if (!res)
		err_exit("malloc failed\n");
	return (res);
}

void			init_philos(t_simulation *sim)
{
	int i;

	i = 0;
	sim->philos = (t_philo*)ft_malloc(sizeof(t_philo) * sim->settings->count);
	while (i < sim->settings->phil_count)
	{
		sim->philos[i].num = i + 1;
		sim->philos[i].state = ST_THINKING;
		sim->philos[i].start_time = &(sim->start_time);
		sim->philos[i].out_mutex = &(sim->out_mutex);
		i++;
	}
}
