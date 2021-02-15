int	ft_isprint(int p)
{
	if (p > 31 && p < 127)
		return (1);
	return (0);
}
