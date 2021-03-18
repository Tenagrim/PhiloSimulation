/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:07:01 by gshona            #+#    #+#             */
/*   Updated: 2021/03/18 14:38:54 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void		wait_for_forks(t_philo *philo)
{
	while(1)
	{
		if (philo->l_philo->state != ST_EATING && philo->r_philo->state != ST_EATING)
			break;
		usleep(P_WAIT_FORK_STEP);
	}
}

void			take_forks(t_philo *philo)
{
	wait_for_forks(philo);
	//printf("%d takes l fork\n", philo->num);
	lock_f(philo->l_fork);
	display_message(philo, ST_TAKE_FORK);
	//printf("%d takes r fork\n", philo->num);
	lock_f(philo->r_fork);
	display_message(philo, ST_TAKE_FORK);
}
