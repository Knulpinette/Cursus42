#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	if (ptr1 == 0 || ptr2 == 0)
		return (0);
	str1 = (unsigned char *)ptr1;
	str2 = (unsigned char *)ptr2;
	i = 0;
	while (i < n)
	{
		if (str1[i] == str2[i])
			i++;
		else
		{
			if (str1[i] < str2[i])
				return (-1);
			if (str1[i] > str2[i])
				return (1);
		}
	}
	return (0);
}
