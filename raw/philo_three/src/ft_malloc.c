/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:00:01 by gshona            #+#    #+#             */
/*   Updated: 2021/03/16 11:14:50 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void		*ft_malloc(unsigned int size)
{
	void	*res;

	res = malloc(size);
	if (!res)
		err_exit("malloc failed\n", 2);
	return (res);
}
