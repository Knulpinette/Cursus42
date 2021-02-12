/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <osurcouf@student.42lisboa.com>          +#+  +:+       +#+ */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 21:06:09 by osurcouf          #+#    #+#             */
/*   Updated: 2021/02/09 13:34:30 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int x, size_t n)
{
	char	*c;
	size_t	i;

	c = (char *)ptr;
	i = 0;
	while (i < n && c[i] != '\0')
	{
		c[i] = x;
		i++;
	}
	return (ptr);
}
