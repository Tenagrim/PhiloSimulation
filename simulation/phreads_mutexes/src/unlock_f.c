#include <philo.h>

int				unlock_f(t_mutex *mut)
{
	return (pthread_mutex_unlock(mut));
}
