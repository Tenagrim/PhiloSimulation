#include <philo.h>

void			drop_forks(t_philo *philo)
{
	unlock_f(philo->l_fork);
	unlock_f(philo->r_fork);
}
