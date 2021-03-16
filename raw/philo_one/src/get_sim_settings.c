/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sim_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 19:57:32 by gshona            #+#    #+#             */
/*   Updated: 2021/03/16 22:07:37 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <philo.h>

void	get_sim_settings(t_sim_settings *setts, char **av)
{
	setts->phil_count = ft_atoi(av[1]);
	setts->time_to_die = ft_atoi(av[2]);
	setts->time_to_eat = ft_atoi(av[3]);
	setts->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		setts->times_must_eat = ft_atoi(av[5]);
	else
		setts->times_must_eat = 0;
}
