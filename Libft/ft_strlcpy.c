size_t	ft_strlen(const char *str)
{
	const char* s;
	
	s = str;
	while (*s)
		s++;
	return (s - str);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while ((src[i] != '\0') && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
