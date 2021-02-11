#include "libft.h"

void	*ft_memccpy(void *to, const void *from, int c, size_t n)
{
	unsigned int i;
	char *dest;
	char *src;

	i = 0;
	if (!to && !from)
		return (NULL);
	dest = (char *)to;
	src = (char *)from;
	while (i < n) 
	{
		if (src[i] == c)
		{
			dest[i] = src[i];
			i++;
			return (to + i);
		}
		if (src[i] != c)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (NULL);
}