/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:31:37 by gshona            #+#    #+#             */
/*   Updated: 2021/03/19 12:17:42 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void			die(t_philo *philo)
{
	if (philo->settings->flags & F_DEBUG)
	{
		write(2, "\x1b[31mDEAD\x1b[0m\n", 14);
	}
	else
	{
	//dprintf(2, "!!!!!!!!!!!!\n");
		display_message(philo, ST_DEAD);
	//dprintf(2, "2!!!!!!!!!!!!\n");
		unlock_f(philo->death_trigger);
	//dprintf(2, "3!!!!!!!!!!!!\n");
	}
}
