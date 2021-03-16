/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep_from.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:28:32 by gshona            #+#    #+#             */
/*   Updated: 2021/03/16 20:40:40 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void			usleep_from(t_timeval *start, unsigned long millis, t_mutex *mut)
{
	unsigned long	udiff;
	unsigned long	time;;
	t_timeval		now;

	get_timestamp(&now, mut);
	udiff = get_time_udiff(start, &now);
	time = millis * 1000 - udiff;
	dprintf(2,"time = {%ld}\n", time / 1000);
	usleep(time);
}
