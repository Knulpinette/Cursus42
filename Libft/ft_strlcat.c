#include "libft.h"

size_t	ft_strlen(const char *str)
{
	const char* s;
	
	s = str;
	while (*s)
		s++;
	return (s - str);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)

{
	unsigned int i;
	unsigned int a;

	i = 0;
	a = ft_strlen(dest);
	if (a == 0)
		return (0);
	while (a + i < size - 1 && src[i] != '\0')
	{
		dest[a + i] = src[i];
		i++;
	}
	dest[a + i] = '\0';
	return (a + ft_strlen(src));
}
