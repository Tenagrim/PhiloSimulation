#include <philo.h>

unsigned long	get_time_udiff(t_timeval *t1, t_timeval *t2)
{
	t_timeval diff;

	diff.tv_sec = t2->tv_sec - t1->tv_sec;
	diff.tv_usec = t2->tv_usec - t1->tv_usec;
	return (diff.tv_sec * 1000000 + diff.tv_usec);
}
