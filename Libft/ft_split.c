#include "libft.h"

char	*ft_trim(char const *s, char c)
{
	char	*trim;
	int		i;
	int		start;
	int		end;

	i = 0;
	start = 0;
	end = ft_strlen(s);
	while (s[start] == c)
		start++;
	while (s[end] == c)
		end--;
	trim = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!(trim))
		return (NULL);
	while (start < end)
	{
		trim[i] = s[start];
		i++;
		start++;
	}
	trim[i] = '\0';
	return (trim);
}

int	nb_words(char c, char *trim)
{
	int	nb;

	nb = 1;
	while (*trim)
	{
		if (*trim == c)
			nb++;
		trim++;
	}
	return (nb);
}

int	size_words(char *trim, char c)
{
	int	i;

	i = 0;
	// vérifier que je fais pas n'importe quoi avec les pointeurs et que les valeurs
	// sont les bonnes !
	while (trim[i] != '\0')
	{
		if (trim[i] == c)
			i++;
	}
	return (i);
}

char	**copysub(char *trim, char c, int nb_words, char **split)
{
	int		a;
	int		b;
	int		size;

	a = 0;
	while (a++ < nb_words && *trim)
	{
		b = 0;
		size = size_words(trim, c);
		split[a] = (char *)malloc(sizeof(char) * (size + 1));
		if (!(split[a]))
			return (NULL);
		while (*trim != c && *trim)
		{
			split[a][b] = *trim;
			b++;
		}
		split[a][b] = '\0';
		while (*trim == c && *trim)
			trim++;
	}
	split[a] = (char *)malloc(sizeof(char) * 1);
	split[a] = 0;
	free(trim);
	return (split);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	*trim;
	char	**split;

	// check with c = \0 !!

	trim = ft_trim(s, c);
	if (!(trim))
		return (NULL);
	words = nb_words(c, trim);
	split = (char **)malloc(sizeof(char *) * words + 1);
	if (!(split))
		return (NULL);
	return (copysub(trim, c, words, split));
}
