#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*str;

	str = malloc(size * n);
	return (ft_memset(str, 0, n));
}
