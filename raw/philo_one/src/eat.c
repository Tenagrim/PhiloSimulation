/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:21:40 by gshona            #+#    #+#             */
/*   Updated: 2021/03/18 14:53:19 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void			eat(t_philo *philo)
{
	t_timeval	prev;
	unsigned long diff;

	/*
	if (philo->times_eated && diff > philo->settings->time_to_die)
	{
		printf("diff = %lu\n", diff);
		die(philo);
	}
	*/
	prev.tv_sec = philo->last_eat.tv_sec;
	prev.tv_usec = philo->last_eat.tv_usec;
	gettimeofday(&(philo->last_eat), philo->get_time_mut);
	diff = get_time_diff(&prev, &philo->last_eat);
	philo->state = ST_EATING;


//	if (diff >= philo->settings->time_to_die - 1)
//	{
	lock_f(philo->out_mutex);
	//dprintf(2," _________ %lu /n", philo->settings->time_to_die);
	//dprintf(2,"[%d] diff = %lu\n",philo->num, diff);
	ft_putunbr_fd(2, diff);
	write(2, " ]\n", 3);
	if(diff > philo->settings->time_to_die + P_WT)
		write(2, "DEAD\n", 5);
	unlock_f(philo->out_mutex);
//	}
	display_message(philo, ST_EATING);


	philo->times_eated += 1;
	usleep_from(&(philo->last_eat), philo->settings->time_to_eat);
}
