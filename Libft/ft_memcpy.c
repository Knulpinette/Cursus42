/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:50:25 by osurcouf          #+#    #+#             */
/*   Updated: 2021/02/18 14:50:27 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *to, const void *from, size_t n)
{
	char	*dest;
	char	*src;
	size_t	i;

	if (!(to) && !(from))
		return (0);
	dest = (char *)to;
	src = (char *)from;
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (to);
}
