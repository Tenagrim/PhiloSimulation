/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:40:57 by gshona            #+#    #+#             */
/*   Updated: 2021/03/19 12:33:23 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
/*
static void		ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
*/
void			display_message(t_philo *philo, int state)
{
	char *str;
	unsigned long time;
	t_timeval t;

	str = "none status";
	get_timestamp(&t, philo->get_time_mut);
	time = get_time_diff(philo->start_time, &t);
	if (state == ST_TAKE_FORK)
		str = ("has taken a fork\n");
	else if (state == ST_EATING)
		str = "is \x1b[32meating\x1b[0m\n";
	else if (state == ST_SLEEPING)
		str = ("is sleeping\n");
	else if (state == ST_THINKING)
		str = ("is thinking\n");
	else if (state == ST_DEAD)
		str = ("is \x1b[31mdied\x1b[0m\n");
	lock_f(philo->out_mutex);
	ft_putunbr_fd(1, time);
	write(1, " ", 1);
	ft_putunbr_fd(1, philo->num);
	write(1, " ", 1);
	write(1, str, ft_strlen(str));
	unlock_f(philo->out_mutex);
}
