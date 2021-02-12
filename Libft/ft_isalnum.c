int	ft_isalnum(int a)
{
	if (a >= 'a' && a <= 'z')
		return (3);
	if (a >= 'A' && a <= 'Z')
		return (2);
	if (a >= '0' && a <= '9')
		return (1);
	return (0);
}