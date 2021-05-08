int		ft_atoi(char *str)
{
	int res;

	res = 0;
	while (*str)
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}
