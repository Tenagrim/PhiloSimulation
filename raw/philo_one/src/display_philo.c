/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:41:49 by gshona            #+#    #+#             */
/*   Updated: 2021/03/15 23:01:50 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void			display_philo(t_philo *philo)
{
	t_timeval	stamp;

	gettimeofday(&stamp, NULL);
	pthread_mutex_lock(philo->out_mutex);
	printf("[%d] %ld\n", philo->num, get_time_diff(philo->start_time, stamp));
	pthread_mutex_unlock(philo->out_mutex);
}
