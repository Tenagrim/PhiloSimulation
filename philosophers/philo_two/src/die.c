/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:31:37 by gshona            #+#    #+#             */
/*   Updated: 2021/03/19 16:45:16 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void			die(t_philo *philo)
{
	if (philo->settings->flags & F_DEBUG)
	{
		lock_f(philo->out_mutex);
		write(2, "\x1b[31mDEAD\x1b[0m\n", 14);
		unlock_f(philo->out_mutex);
		philo->settings->deaths += 1;
	}
	else
	{
		display_message(philo, ST_DEAD);
		lock_f(philo->out_mutex);
		philo->settings->flags |= F_ENDED;
		unlock_f(philo->death_trigger);
	}
}
