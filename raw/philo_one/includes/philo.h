/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 19:57:35 by gshona            #+#    #+#             */
/*   Updated: 2021/03/15 20:38:37 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_sim_settings
{
	unsigned int	phil_count;
	unsigned int	time_to_die;
	unsigned int	time_to_sleep;
	unsigned int	time_to_eat;
	int				times_must_eat;

}				t_sim_settings;

typedef struct
{
	t_sim_settings	settings;
}				t_simulation;
void			get_sim_settings(t_sim_settings *setts, char **av);
void			err_exit(char *str, int code);
int				ft_strlen(char *str);
void			check_input(int ac, char **av);
void			print_settings(t_sim_settings *setts);
int				ft_atoi(char *str);
#endif
