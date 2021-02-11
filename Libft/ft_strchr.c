char	*ft_strchr(const char *str, int c)
{
	const char* s;
	
	s = str;
	while (*s)
		s++;
	while (*s != *str)
	{
		if (*str == c)
			return ((char *)str);
		else
			str++;
	}
	if (c == '\0' && *(str + 1) == '\0')
		return ((char *)(str + 1));
	return (NULL);
}