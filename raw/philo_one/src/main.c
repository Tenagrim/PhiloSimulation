/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:05:56 by gshona            #+#    #+#             */
/*   Updated: 2021/03/19 12:43:34 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int main(int ac, char **av)
{
	//t_sim_settings	setts;
	t_simulation sim;
	check_input(ac, av);
	get_sim_settings(&sim.settings, av);
	if (sim.settings.flags & F_DEBUG)
		print_settings(&sim.settings);
	init_simulation(&sim);

	//for(int i = 0; i < sim.settings.phil_count; i++)
	//	display_philo(sim.philos+i);

	run_simulation(&sim);
	destroy_simulation(&sim);
}

/*
	struct timeval t1;
	struct timeval t2;
	gettimeofday(&t1, NULL);
	unsigned long diff;
	int i = 0;
	//  printf("seconds       : %ld\nmicro seconds : %ld\n", tp.tv_sec, tp.tv_usec);
	while (1)
	{
		gettimeofday(&t2, NULL);
		diff = get_time_diff(&t1, &t2);
		printf("passed %ld milliseconds [%ld]\n", diff, diff - i * 1000);
		i++;
		usleep(1000000);
	}
	*/
