/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sem_open.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 19:05:19 by gshona            #+#    #+#             */
/*   Updated: 2021/03/19 21:38:26 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_mutex					*ft_sem_open(const char *name, int value)
{
	sem_unlink(name);
	return (sem_open(name, O_CREAT, 0644, value));
}
