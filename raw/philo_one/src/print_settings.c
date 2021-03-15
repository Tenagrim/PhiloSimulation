/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:20:02 by gshona            #+#    #+#             */
/*   Updated: 2021/03/15 20:39:27 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void			print_settings(t_sim_settings *setts)
{
	printf("phil count:     %u\n", setts->phil_count);
	printf("time to die:    %u\n", setts->time_to_die);
	printf("time to sleep:  %u\n", setts->time_to_sleep);
	printf("time to eat:    %u\n", setts->time_to_eat);
	printf("times must eat: %d\n", setts->times_must_eat);
}
