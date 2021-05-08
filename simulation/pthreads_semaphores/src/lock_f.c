#include <philo.h>

int				lock_f(t_mutex *mut)
{
	return (sem_wait(mut));
}
