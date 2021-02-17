#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				size;
	char			*mapi;
	unsigned int	i;

	i = 0;
	size = ft_strlen(s);
	mapi = (char *)malloc(sizeof(char) * size + 1);
	while (s[i] != '\0')
	{
		mapi[i] = f(i, s[i]);
		i++;
	}
	return (mapi);
}
