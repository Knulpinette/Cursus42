#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	const char* s;
	
	s = str;
	while (*s)
		s++;
	return (s - str);
}

char	*ft_strdup(const char *src)
{
	char	*ptr;
	unsigned int		len_src;
	int		i;

	i = 0;
	len_src = str_len(src);
	if (len_src == 0)
	{
		ptr = malloc(sizeof(char));
		ptr[0] = '\0';
		return (ptr);
	}
	ptr = malloc(sizeof(*ptr) * len_src + 1);
	if (ptr == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
