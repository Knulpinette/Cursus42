/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:50:58 by osurcouf          #+#    #+#             */
/*   Updated: 2021/02/18 14:50:59 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int x, size_t n)
{
	char	*c;
	size_t	i;

	c = (char *)ptr;
	i = 0;
	while (i < n)
	{
		c[i] = x;
		i++;
	}
	return (ptr);
}
