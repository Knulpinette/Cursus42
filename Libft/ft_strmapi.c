/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:53:03 by osurcouf          #+#    #+#             */
/*   Updated: 2021/02/18 14:53:05 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	const char		*s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				size;
	char			*mapi;
	unsigned int	i;

	i = 0;
	size = ft_strlen(s);
	mapi = (char *)malloc(sizeof(char) * (size + 1));
	while (s[i] != '\0')
	{
		mapi[i] = f(i, s[i]);
		i++;
	}
	mapi[i] = 0;
	return (mapi);
}
