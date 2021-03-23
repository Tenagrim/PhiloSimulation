/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:21:40 by gshona            #+#    #+#             */
/*   Updated: 2021/03/19 17:11:07 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void		debug_write(unsigned long diff, t_philo *philo)
{
	lock_f(philo->out_mutex);
	ft_putunbr_fd(2, diff);
	write(2, " ]\n", 3);
	unlock_f(philo->out_mutex);
	if (diff > philo->settings->starving)
		philo->settings->starving = diff;
	if (philo->times_eated && diff < philo->settings->fastest)
		philo->settings->fastest = diff;
}

void			eat(t_philo *philo)
{
	t_timeval		prev;
	unsigned long	diff;

	prev.tv_sec = philo->last_eat.tv_sec;
	prev.tv_usec = philo->last_eat.tv_usec;
	get_timestamp(&(philo->last_eat), philo->get_time_mut);
	diff = get_time_diff(&prev, &philo->last_eat);
	philo->state = ST_EATING;
	if (philo->settings->flags & F_DEBUG)
		debug_write(diff, philo);
	display_message(philo, ST_EATING);
	philo->times_eated += 1;
	usleep_from(&(philo->last_eat), philo->settings->time_to_eat,
			philo->get_time_mut);
}
