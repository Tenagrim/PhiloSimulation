/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:30:07 by gshona            #+#    #+#             */
/*   Updated: 2021/03/19 17:10:13 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int res;

	res = 0;
	while (*str)
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}
