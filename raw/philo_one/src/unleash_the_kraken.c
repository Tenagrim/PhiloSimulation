/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unleash_the_kraken.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 12:52:06 by gshona            #+#    #+#             */
/*   Updated: 2021/03/19 13:18:24 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void				your_time_s_up(t_philo *philo)
{
	display_message(philo, ST_DEAD);
	unlock_f(philo->death_trigger);
}

static void			*bloody_harvest(void *sea_of_bloood)
{
	t_simulation	*sea;
	unsigned int	i;
	t_timeval		good_time_to_die;
	unsigned long	edge_of_life_and_death;

	sea = (t_simulation*)sea_of_bloood;
	while (1)
	{
		i = 0;
		while (i < sea->settings.phil_count)
		{
			get_timestamp(&good_time_to_die, &(sea->get_time_mut));
			edge_of_life_and_death = get_time_diff(&(sea->philos[i].last_eat), &good_time_to_die);
			if (edge_of_life_and_death > sea->settings.time_to_die)
			{
				your_time_s_up(&(sea->philos[i]));
				return (NULL);
			}
			i++;
		}
		usleep(P_KRAKEN_S_LUNCH);
	}
}

void					unleash_the_kraken(t_simulation *sim)
{
	int r;

	r = pthread_create(&(sim->kraken), NULL, bloody_harvest, (void*)sim);
}
