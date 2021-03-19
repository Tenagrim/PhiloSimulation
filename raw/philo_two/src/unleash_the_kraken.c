/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unleash_the_kraken.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 12:52:06 by gshona            #+#    #+#             */
/*   Updated: 2021/03/19 19:18:30 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void				set_this_right_mortal(unsigned int *i,
		unsigned int *escaped)
{
	*i = -1;
	*escaped = 0;
}

static int			chance_to_escape_the_death(t_simulation *sea,
		unsigned int escaped)
{
	if (sea->settings.times_must_eat && escaped == sea->settings.phil_count)
	{
		unlock_f(sea->death_trigger);
		return (0);
	}
	return (1);
}

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
	unsigned int	escaped;

	sea = (t_simulation*)sea_of_bloood;
	while (1)
	{
		set_this_right_mortal(&i, &escaped);
		while (++i < sea->settings.phil_count)
		{
			if (sea->philos[i].state == ST_DEAD)
				continue;
			if (sea->philos[i].times_eated >= sea->settings.times_must_eat)
				escaped++;
			get_timestamp(&good_time_to_die, sea->get_time_mut);
			edge_of_life_and_death = get_time_diff(&(sea->philos[i].last_eat),
					&good_time_to_die);
			if (to_kill_or_not_to_kill(sea, edge_of_life_and_death, i))
				return (NULL);
		}
		if (!chance_to_escape_the_death(sea, escaped))
			return (NULL);
	}
}

void				unleash_the_kraken(t_simulation *sim)
{
	int r;

	r = pthread_create(&(sim->kraken), NULL, bloody_harvest, (void*)sim);
	if (r != 0)
		err_exit("failed to start tread\n", 3);
	pthread_detach(sim->kraken);
}
