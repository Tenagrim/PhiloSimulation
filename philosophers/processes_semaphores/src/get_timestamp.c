#include <philo.h>

int				get_timestamp(t_timeval *tv, t_mutex *mut)
{
	lock_f(mut);
	gettimeofday(tv, NULL);
	unlock_f(mut);
	return (0);
}
