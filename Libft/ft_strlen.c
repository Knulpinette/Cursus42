#include "libft.h"

size_t	ft_strlen(const char *str)
{
	const char		*s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}
