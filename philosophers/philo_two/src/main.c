/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:05:56 by gshona            #+#    #+#             */
/*   Updated: 2021/03/19 19:23:26 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void		print_settings_(t_simulation *sim)
{
	if (sim->settings.flags & F_DEBUG)
		print_settings(&sim->settings);
}

static void		print_summary(t_simulation *sim)
{
	if (sim->settings.flags & F_DEBUG)
	{
		printf("\n=========== SUMMARY ==============\n=\n");
		printf("= deaths:           %u\n", sim->settings.deaths);
		printf("= longest starving: %lu\n", sim->settings.starving);
		printf("= fastest eater:    %lu\n", sim->settings.fastest);
		printf("=\n==================================\n");
	}
}

int				main(int ac, char **av)
{
	t_simulation sim;

	check_input(ac, av);
	get_sim_settings(&sim.settings, av);
	print_settings_(&sim);
	init_simulation(&sim);
	run_simulation(&sim);
	print_summary(&sim);
	destroy_simulation(&sim);
	return (0);
}
