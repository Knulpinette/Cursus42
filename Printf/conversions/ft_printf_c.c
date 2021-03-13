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

void	ft_printf_c(va_list arg)
{
	char	c;

	c = (char)(va_arg(arg, int));
	ft_putchar_fd(c, 1);
	return ;
}

/*char	*ft_printf_c(va_list arg)
{
	char *conv;

	conv = (char *)malloc(sizeof(char) * 2);
	conv[0] = (char)(va_arg(arg, int));
	conv[1] = '\0';
	return(conv);
}*/


