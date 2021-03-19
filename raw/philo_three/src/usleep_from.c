/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep_from.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:28:32 by gshona            #+#    #+#             */
/*   Updated: 2021/03/19 16:37:58 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void			usleep_from(t_timeval *start, unsigned long millis,
		t_mutex *mut)
{
	unsigned long	udiff;
	t_timeval		now;

	while (1)
	{
		get_timestamp(&now, mut);
		udiff = get_time_udiff(start, &now);
		if (udiff > millis * 1000)
			break ;
		usleep(P_USLEEP_STEP);
	}
}
