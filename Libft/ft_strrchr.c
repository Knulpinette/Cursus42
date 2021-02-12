char	*ft_strrchr(const char *str, int c)
{
	const char		*s;

	s = str;
	while (*s)
		s++;
	if (c == '\0' && *(s + 1) == '\0')
		return ((char *)(s + 1));
	while (*s != *str)
	{
		if (*s == c)
			return ((char *)s);
		else
			s--;
	}
	return (0);
}
