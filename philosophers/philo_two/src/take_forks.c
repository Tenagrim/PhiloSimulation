/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:07:01 by gshona            #+#    #+#             */
/*   Updated: 2021/03/19 16:05:48 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void			take_forks(t_philo *philo)
{
	lock_f(philo->l_fork);
	display_message(philo, ST_TAKE_FORK);
	lock_f(philo->r_fork);
	display_message(philo, ST_TAKE_FORK);
}
