/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:38:31 by gshona            #+#    #+#             */
/*   Updated: 2021/03/16 20:44:39 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void			sleep_(t_philo *philo)
{
	display_message(philo, ST_SLEEPING);
	philo->state = ST_SLEEPING;
	usleep(philo->settings->time_to_sleep * 1000);
	//usleep_from(&(philo->last_eat), philo->settings->time_to_sleep + philo->settings->time_to_eat, philo->get_time_mut);
}
