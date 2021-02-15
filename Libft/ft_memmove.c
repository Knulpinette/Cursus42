#include "libft.h"

void	*ft_memmove(void *to, const void *from, size_t n)
{
	char	*dest;
	char	*src;
	size_t	i;

	if (!to && !from)
		return (0);
	dest = (char *)to;
	src = (char *)from;
	if (src + 1 == dest)
	{
		while (n-- > 0)
			dest[n] = src[n];
		dest[n] = src[n];
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
