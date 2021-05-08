#include <philo.h>

void			ft_putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
}

void			ft_putunbr_fd(int fd, long unsigned int n)
{
	if (n < 10)
		ft_putchar_fd(fd, n + '0');
	else
	{
		ft_putunbr_fd(fd, n / 10);
		ft_putchar_fd(fd, (n % 10) + '0');
	}
}
