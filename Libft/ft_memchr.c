/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:49:11 by osurcouf          #+#    #+#             */
/*   Updated: 2021/02/18 14:49:13 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)ptr;
	c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == c)
			return ((void *)ptr + i);
		else
			i++;
	}
	return (NULL);
}
