/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:41:49 by gshona            #+#    #+#             */
/*   Updated: 2021/03/16 14:57:12 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void			display_philo(t_philo *philo)
{
	printf("==========================\n");
	printf("num:     %u\n", philo->num);
	printf("adress:  %p\n", philo);
	printf("state:   %d\n", philo->state);
	printf("eated:   %u\n", philo->times_eated);
	printf("out mut: %p\n", philo->out_mutex);
	printf("l philo: %p\n", philo->l_philo);
	printf("r philo: %p\n", philo->r_philo);
	printf("l fork:  %p\n", philo->l_fork);
	printf("r fork:  %p\n", philo->r_fork);
	printf("==========================\n");
}
