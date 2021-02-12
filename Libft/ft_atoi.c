int	ft_atoi(const char *str)
{
	int	i;
	int	np;
	int	nbr;

	i = 0;
	nbr = 0;
	np = 1;
	while (str[i] != '\0' && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] != '\0' && str[i] == '+')
		i++;
	if (str[i] != '\0' && str[i] == '-')
	{
		np = np * -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (nbr * np);
}
