#include <philo.h>

static void		write_(unsigned long time, t_philo *philo, char *str)
{
	lock_f(philo->out_mutex);
	ft_putunbr_fd(1, time);
	write(1, " ", 1);
	ft_putunbr_fd(1, philo->num);
	write(1, " ", 1);
	write(1, str, ft_strlen(str));
	unlock_f(philo->out_mutex);
}

void			display_message(t_philo *philo, int state)
{
	char			*str;
	unsigned long	time;
	t_timeval		t;

	if (philo->settings->flags & F_ENDED)
		exit(0);
	str = "none status";
	get_timestamp(&t, philo->get_time_mut);
	time = get_time_diff(philo->start_time, &t);
	if (state == ST_TAKE_FORK)
		str = ("has taken a fork\n");
	else if (state == ST_EATING)
		str = "is \x1b[32meating\x1b[0m\n";
	else if (state == ST_SLEEPING)
		str = ("is sleeping\n");
	else if (state == ST_THINKING)
		str = ("is thinking\n");
	else if (state == ST_DEAD)
		str = ("is \x1b[31mdied\x1b[0m\n");
	write_(time, philo, str);
}
