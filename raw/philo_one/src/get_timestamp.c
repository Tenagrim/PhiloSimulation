/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:58:16 by gshona            #+#    #+#             */
/*   Updated: 2021/03/17 21:19:26 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int				get_timestamp(t_timeval *tv, t_mutex *mut)
{
	//lock_f(mut);
	gettimeofday(tv, NULL);
	//unlock_f(mut);
	return (0);
}