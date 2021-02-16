char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	a;

	i = 0;
	a = (char)c;
	while (str[i] != '\0')
		i++;
	if (a == '\0' && str[i] == '\0')
		return ((char *)str + i);
	while (i >= 0)
	{
		if (str[i] == a)
			return ((char *)str + i);
		else
			i--;
	}
	return (0);
}
