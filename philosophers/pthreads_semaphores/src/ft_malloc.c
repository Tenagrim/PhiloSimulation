#include <philo.h>

void		*ft_malloc(unsigned int size)
{
	void	*res;

	res = malloc(size);
	if (!res)
		err_exit("malloc failed\n", 2);
	return (res);
}
