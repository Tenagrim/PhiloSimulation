/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circuled_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:36:42 by gshona            #+#    #+#             */
/*   Updated: 2021/03/19 17:09:52 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int				circuled_num(int value, int size)
{
	if (value == size)
		return (0);
	if (value == -1)
		return (size - 1);
	return (value);
}
