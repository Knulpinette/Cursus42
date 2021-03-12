/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:34:00 by osurcouf          #+#    #+#             */
/*   Updated: 2021/03/12 13:34:02 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_printf_u(unsigned int u)
{	
	int	conv;

	conv = (int)u;
	if (conv < 0)
		return (NULL);
	return(ft_itoa(conv));
}

