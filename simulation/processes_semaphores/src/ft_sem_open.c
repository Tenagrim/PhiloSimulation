#include <philo.h>

t_mutex					*ft_sem_open(const char *name, int value)
{
	sem_unlink(name);
	return (sem_open(name, O_CREAT, 0644, value));
}
