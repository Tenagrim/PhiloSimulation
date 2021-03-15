/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_diff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 21:19:49 by gshona            #+#    #+#             */
/*   Updated: 2021/03/15 21:30:51 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

unsigned long	get_time_diff(t_timeval *t1, t_timeval *t2)
{
	t_timeval diff;
	diff.tv_sec = t2->tv_sec - t1->tv_sec;
	diff.tv_usec = t2->tv_usec - t1->tv_usec;
	return (diff.tv_sec * 1000 + diff.tv_usec / 1000);
}
