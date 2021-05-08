#include <philo.h>

static int	all_numeric(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	while (i < ac)
	{
		if (ac >= 6 && i == ac - 1 && !ft_strcmp(av[i], "--debug"))
		{
			i++;
			continue ;
		}
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void		check_input(int ac, char **av)
{
	if (ac < 5 || (ac > 7) || (ac == 7 && ft_strcmp(av[6], "--debug")))
		err_exit("Wrong number of arguments\n", 1);
	if (!all_numeric(ac, av))
		err_exit("Wrong arguments\n", 2);
}
