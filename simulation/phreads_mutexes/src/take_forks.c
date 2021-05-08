#include <philo.h>

void			take_forks(t_philo *philo)
{
	lock_f(philo->l_fork);
	display_message(philo, ST_TAKE_FORK);
	lock_f(philo->r_fork);
	display_message(philo, ST_TAKE_FORK);
}
