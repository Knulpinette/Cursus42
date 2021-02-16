#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*bzero;

	bzero = (char *)s;
	while (n > 0)
	{
		bzero[n - 1] = '\0';
		n--;
	}
}
