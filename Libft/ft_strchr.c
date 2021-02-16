char	*ft_strchr(const char *str, int c)
{
	char	a;

	a = (char)c;
	while (*str)
	{
		if (*str == a)
			return ((char *)str);
		str++;
	}
	if (c == '\0' && *str == '\0')
		return ((char *)str);
	return (0);
}
