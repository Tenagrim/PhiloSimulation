#include <philo.h>

int				lock_f(t_mutex *mut)
{
	return (pthread_mutex_lock(mut));
}
