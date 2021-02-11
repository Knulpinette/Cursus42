void	*ft_memchr(const void *ptr, int c, size_t n)
{
	unsigned char *str;
	unsigned int i;

	str = (unsigned char *)ptr;
	c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == c)
			return ((void *)ptr + i);
		else 
			i++;
	}
	return (NULL);
}