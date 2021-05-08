#include <philo.h>

int				unlock_f(t_mutex *mut)
{
	return (sem_post(mut));
}
