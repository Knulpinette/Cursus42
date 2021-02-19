/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:39:21 by osurcouf          #+#    #+#             */
/*   Updated: 2021/02/18 14:47:30 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*str;

// handle empty string for n = 0 ; n = 1 ?
	str = (void *)malloc(size * n);
	if (!str)
		return (NULL);
	ft_memset(str, 0, n);
	return (str);
}
