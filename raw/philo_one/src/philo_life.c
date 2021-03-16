/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:21:49 by gshona            #+#    #+#             */
/*   Updated: 2021/03/16 20:53:03 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void			*philo_life(void *args)
{
	t_philo	*philo;

	struct timeval t1;
	struct timeval t2;
	unsigned long diff;

	philo = (t_philo*) args;
	//lock_f(philo->out_mutex);
	//printf("========== STARTED =============");
	//display_philo(philo);
	//unlock_f(philo->out_mutex);

	//	lock_f(philo->out_mutex);
	//	printf("philo started [%d]\n",philo->num);
	//	unlock_f(philo->out_mutex);

	//gettimeofday(&t1, NULL);
	//get_timestamp(&t1, philo->get_time_mut);

	///gettimeofday(&t1, NULL);
	//int i = 0;
	while (1)
	{
		//lock_f(philo->out_mutex);
		//display_philo(philo);
		//unlock_f(philo->out_mutex);
		//gettimeofday(&t2, NULL);
		//get_timestamp(&t2, philo->get_time_mut);
		//diff = get_time_diff(&t1, &t2);
	//	lock_f(philo->out_mutex);
		//printf("[%d] passed %ld milliseconds [%ld]\n",philo->num, diff, diff - i * 1000);
	//	unlock_f(philo->out_mutex);
		//i++;
		//if (diff > 10000)
		//	unlock_f(philo->death_trigger);
		//usleep(1000000);
		//get_timestamp(&t1, philo->get_time_mut);
		take_forks(philo);
		/*
		get_timestamp(&t2, philo->get_time_mut);
		diff = get_time_diff(&t1, &t2);
		dprintf(2,"fork waiting {%lu}\n", diff);

		get_timestamp(&t1, philo->get_time_mut);
		*/
		eat(philo);
/*
		get_timestamp(&t2, philo->get_time_mut);
		diff = get_time_diff(&t1, &t2);
		dprintf(2,"eating  {%lu}\n", diff);
*/
		if (philo->settings->times_must_eat && philo->times_eated == philo->settings->times_must_eat)
		{
			drop_forks(philo);
			philo->state = ST_SLEEPING;
			return (NULL);
		}
		drop_forks(philo);

		//get_timestamp(&t1, philo->get_time_mut);
		sleep_(philo);
		//get_timestamp(&t2, philo->get_time_mut);
		//diff = get_time_diff(&t1, &t2);
		//dprintf(2,"sleeping  {%lu}\n", diff);

		display_message(philo, ST_THINKING);
	}
}
