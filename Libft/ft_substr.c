#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (start > ft_strlen(s))
	{
		sub = (char *)malloc(sizeof(char) * 1);
		sub[0] = 0;
		return (sub);
	}
	sub = (char *)malloc(sizeof(char) * len + 1);
	if (!(sub))
		return (NULL);
	while (s[start + i] != '\0' && i < len)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
