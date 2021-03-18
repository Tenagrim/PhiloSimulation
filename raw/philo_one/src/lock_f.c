/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:45:58 by gshona            #+#    #+#             */
/*   Updated: 2021/03/16 11:16:35 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <philo.h>

int				lock_f(t_mutex *mut)
{
	return (pthread_mutex_lock(mut));
}