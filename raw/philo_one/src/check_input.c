/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:07:28 by gshona            #+#    #+#             */
/*   Updated: 2021/03/15 20:18:40 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <philo.h>

static int	all_numeric(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void		check_input(int ac, char **av)
{	
	if (ac < 5 || ac > 6)
		err_exit("Wrong number of arguments\n", 1);
	if (!all_numeric(ac, av))
		err_exit("Wrong arguments\n", 2);
}
