#include "libft.h"

void	*calloc(size_t n, size_t size)
{
	char	*str;

	str = malloc(sizeof(size) * n);
	while (n > 0)
	{
		str[n] = 0;
		n--;
	}
	return ((void *)str);
}
