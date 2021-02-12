#include "libft.h"

int	check_little(const char *big, const char *little, size_t len, size_t i)
{
	int	a;

	a = 0;
	while (i < len && little[a] != '\0' && big[i] != '\0')
	{
		if (big[i] != little[a])
			return (0);
		a++;
		i++;
	}
	if (little[a] == '\0')
		return (1);
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!(*little))
		return ((char *)big);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		if (little[0] == big[i] && check_little(big, little, len, i) == 1)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
