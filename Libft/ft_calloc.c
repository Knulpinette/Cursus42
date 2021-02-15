#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*str;

	str = malloc(size * n);
	while (n > 0)
	{
		str[n - 1] = 0;
		n--;
	}
	return ((void *)str);
}
