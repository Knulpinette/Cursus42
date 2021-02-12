#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	char *str1;
	char *str2;
	size_t i;

	str1 = (char*)ptr1;
	str2 = (char*)ptr2;
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