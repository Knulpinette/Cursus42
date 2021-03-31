/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:44:04 by osurcouf          #+#    #+#             */
/*   Updated: 2021/03/03 11:44:30 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	const char		*s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}

char	*ft_strdup(const char *src)
{
	char			*ptr;
	unsigned int	len_src;
	int				i;

	i = 0;
	len_src = ft_strlen(src);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			i;

	i = 0;
	if (start > ft_strlen(s))
	{
		sub = (char *)malloc(sizeof(char) * 1);
		if (!sub)
			return (NULL);
		sub[0] = 0;
		return (sub);
	}
	if (ft_strlen(s) - start < len)
		sub = (char *)malloc(sizeof(char) * ((ft_strlen(s) - start + 1)));
	else
		sub = (char *)malloc(sizeof(char) * (len + 1));
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

char	*ft_strchr(const char *str, int c)
{
	char			a;

	a = (char)c;
	while (*str)
	{
		if (*str == a)
			return ((char *)str);
		str++;
	}
	if (c == '\0' && *str == '\0')
		return ((char *)str);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*join;
	int				i;

	i = 0;
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(join))
		return (NULL);
	while (*s1)
	{
		join[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		join[i] = *s2;
		i++;
		s2++;
	}
	join[i] = '\0';
	return (join);
}
