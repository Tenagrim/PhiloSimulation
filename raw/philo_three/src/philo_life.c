/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:21:49 by gshona            #+#    #+#             */
/*   Updated: 2021/03/19 21:15:51 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void			*philo_life(void *args)
{
	t_philo		*philo;

	philo = (t_philo*)args;
	while (1)
	{
		take_forks(philo);
		eat(philo);
		drop_forks(philo);
		if (philo->settings->times_must_eat &&
				philo->times_eated == philo->settings->times_must_eat)
		{
			unlock_f(philo->eat_up_trigger);
			usleep((philo->settings->time_to_eat +
					philo->settings->time_to_sleep) * 4000);
		}
		sleep_(philo);
		display_message(philo, ST_THINKING);
	}
}
