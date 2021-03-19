/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sim_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 19:57:32 by gshona            #+#    #+#             */
/*   Updated: 2021/03/19 11:51:56 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <philo.h>

static void	d_key(t_sim_settings *setts, char **av)
{
	if ((av[5] && !ft_strcmp(av[5], "--debug"))
			|| (av[6] && !ft_strcmp(av[6], "--debug")))
			setts->flags |= F_DEBUG;
}

void		get_sim_settings(t_sim_settings *setts, char **av)
{
	setts->phil_count = ft_atoi(av[1]);
	setts->time_to_die = ft_atoi(av[2]);
	setts->time_to_eat = ft_atoi(av[3]);
	setts->time_to_sleep = ft_atoi(av[4]);
	setts->flags = 0;
	if (av[5] && ft_strcmp(av[5], "--debug"))
		setts->times_must_eat = ft_atoi(av[5]);
	else
		setts->times_must_eat = 0;
	d_key(setts, av);
}
