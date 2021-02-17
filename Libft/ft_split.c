#include "libft.h"

int	nb_words(char c, char const *s, int start)
{
	int	nb;

	nb = 0;
	while (s[start] != '\0')
	{
		nb++;
		while (s[start] != c)
			start++;
		while (s[start] == c)
			start++;
	}
	return (nb);
}

int	size_words(char const *s, char c)
{
	int	i;

	i = 0;
	// vérifier que je fais pas n'importe quoi avec les pointeurs et que les valeurs
	// sont les bonnes !
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

char	**copysub(char const *s, char c, int nb_words, char **split)
{
	int		a;
	int		b;
	int		size;

	a = -1;
	while (++a < nb_words && *s)
	{
		b = 0;
		size = size_words(s, c);
		split[a] = (char *)malloc(sizeof(char) * (size + 1));
		if (!(split[a]))
			return (NULL);
		while (*s != c && *s)
		{
			split[a][b] = *s;
			b++;
			s++;
		}
		split[a][b] = '\0';
		while (*s == c && *s)
			s++;
	}
	split[a] = (char *)malloc(sizeof(char) * 1);
	split[a] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	int		start;
	char	**split;

	// check with c = \0 !!
	start = 0;
	while (s[start] == c)
		start++;
	words = nb_words(c, s, start);
	if (words == 1 || !(s))
	{
		split = (char **)malloc(sizeof(char *) * 1);
		split = 0;
		return (split);
	}
	split = (char **)malloc(sizeof(char *) * words + 1);
	if (!(split))
		return (NULL);
	while (*s == c)
		s++;
	return (copysub(s, c, words, split));
}
