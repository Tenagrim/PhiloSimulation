#include <philo.h>

int				circuled_num(int value, int size)
{
	if (value == size)
		return (0);
	if (value == -1)
		return (size - 1);
	return (value);
}
