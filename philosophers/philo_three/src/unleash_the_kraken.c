/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unleash_the_kraken.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 12:52:06 by gshona            #+#    #+#             */
/*   Updated: 2021/03/19 21:18:19 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int			to_kill_or_not_to_kill(t_simulation *sea,
		unsigned long int edge_of_life_and_death, int i)
{
	if (edge_of_life_and_death > sea->settings.time_to_die)
	{
		die(&(sea->philos[i]));
		if (!(sea->settings.flags & F_DEBUG))
			return (1);
		else
			sea->philos[i].state = ST_DEAD;
	}
	usleep(P_KRAKEN_S_LUNCH);
	return (0);
}

static void			*bloody_harvest(void *sea_of_bloood)
{
	t_simulation	*sea;
	unsigned int	i;
	t_timeval		good_time_to_die;
	unsigned long	edge_of_life_and_death;

	sea = (t_simulation*)sea_of_bloood;
	i = sea->cur_philo;
	while (1)
	{
		if (sea->philos[i].state == ST_DEAD)
			continue;
		get_timestamp(&good_time_to_die, sea->get_time_mut);
		edge_of_life_and_death = get_time_diff(&(sea->philos[i].last_eat),
				&good_time_to_die);
		if (to_kill_or_not_to_kill(sea, edge_of_life_and_death, i))
			return (NULL);
	}
}

void				unleash_the_kraken(t_simulation *sim)
{
	int r;

	usleep(1000);
	r = pthread_create(&(sim->threads[sim->cur_philo]), NULL,
			bloody_harvest, (void*)sim);
	if (r != 0)
		err_exit("failed to unleash the kraken\n", 3);
	pthread_detach(sim->threads[sim->cur_philo]);
}
