/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:49:00 by osurcouf          #+#    #+#             */
/*   Updated: 2021/02/18 14:49:02 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *to, const void *from, int c, size_t n)
{
	size_t	i;
	char	*dest;
	char	*src;

	i = 0;
	if (!to && !from)
		return (NULL);
	dest = (char *)to;
	src = (char *)from;
	while (i < n)
	{
		if (src[i] == c)
		{
			dest[i] = src[i];
			i++;
			return (to + i);
		}
		if (src[i] != c)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (NULL);
}
