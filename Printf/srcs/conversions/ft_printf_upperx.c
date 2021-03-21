/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_X.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:34:11 by osurcouf          #+#    #+#             */
/*   Updated: 2021/03/12 13:34:13 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

char	*ft_printf_X(va_list arg, flags_list *flags)
{	
	char	*conv;
	int		len;

	conv = ft_itoa_convert_base(va_arg(arg, int), "0123456789ABCDEF");
	if (!conv)
		return (NULL);
	len = (int)ft_strlen(conv);
	if ((flags->precision + 1) > len)
	{
		conv = align_nb_precision(flags->precision, conv, len);
		len = (int)ft_strlen(conv);
	}
	if (flags->width > len)
		conv = define_align_width(conv, flags, len);
	return (conv);
}

