int	ft_isprint(int p)
{
	if (p >= 32 && p <= 127)
		return (1);
	return (0);
}