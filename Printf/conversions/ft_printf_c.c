/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:33:27 by osurcouf          #+#    #+#             */
/*   Updated: 2021/03/12 13:33:28 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_printf_c(int c)
{
	char *conv;

	conv = (char *)malloc(sizeof(char) * 2);
	conv[0] = c;
	conv[1] = '\0';
	return(conv);
}


