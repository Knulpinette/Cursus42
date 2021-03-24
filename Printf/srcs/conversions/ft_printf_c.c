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

#include "../../include/ft_printf.h"

char	*ft_printf_c(va_list arg, flags_list *flags)
{
	char *conv;

	conv = (char *)malloc(sizeof(char) * 2);
	conv[0] = (char)(va_arg(arg, int));
	conv[1] = '\0';
	if (flags->width > 1)
	{
		flags->zero = 0;
		//if (flags->minus == minus && conv[0] == '\0')
		//	flags->minus == 0;
		conv = define_align_width(conv, flags, 1);
	}
	return(conv);
}
