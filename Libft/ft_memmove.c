#include "libft.h"

void	*ft_memmove(void *to, const void *from, size_t n)
{
	char		*dest;
	const char	*src;
	size_t		i;

	if (!to && !from)
		return (NULL);
	dest = (char *)to;
	src = (const char *)from;
	if (src + 1 == dest)
	{
		i = n;
		while (i-- > 0)
			dest[i - 1] = src[i - 1];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (to);
}
