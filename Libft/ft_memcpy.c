#include "libft.h"

void	*ft_memcpy(void *to, const void *from, size_t numBytes)
{
	char		*dest;
	const char	*src;
	size_t		i;

	dest = (char *)to;
	src = (const char *)from;
	i = 0;
	while (i < numBytes)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (to);
}
