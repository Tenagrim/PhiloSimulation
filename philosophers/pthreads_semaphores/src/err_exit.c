#include <philo.h>

void	err_exit(char *str, int code)
{
	write(2, str, ft_strlen(str));
	exit(code);
}
