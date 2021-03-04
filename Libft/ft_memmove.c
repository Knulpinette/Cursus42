/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:50:36 by osurcouf          #+#    #+#             */
/*   Updated: 2021/02/18 14:50:49 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*backward(char *dest, char *src, size_t n)
{
	while (n > 0)
	{
		dest[n - 1] = src[n - 1];
		n--;
	}
	return (dest);
}

static char	*forward(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

void		*ft_memmove(void *to, const void *from, size_t n)
{
	char	*dest;
	char	*src;

	if (!to && !from)
		return (0);
	dest = (char *)to;
	src = (char *)from;
	if (src < dest)
		backward(dest, src, n);
	else
		forward(dest, src, n);
	return (to);
}
