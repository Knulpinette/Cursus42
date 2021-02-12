int	ft_tolower(int l)
{
	if (l >= 'A' && l <= 'Z')
		return (l + 32);
	return (l);
}
