/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:33:56 by osurcouf          #+#    #+#             */
/*   Updated: 2021/03/12 13:33:57 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

/*
** 🦕
** function : to DO + clean
** 🦕
*/

char	*convert_i(va_list arg, flags_list *flags)
{
	char	*conv;
	int		len;

	conv = ft_itoa(va_arg(arg, int));
	if (!conv)
		return (NULL);
	len = (int)ft_strlen(conv);
	if (flags->dot && !flags->precision && conv[0] == '0')
	{
		free(conv);
		if (!flags->width)
			return (ft_strdup("\0"));
		conv = ft_strdup(" ");
	}
	if ((flags->precision + 1) > len)
	{
		conv = align_nb_precision(flags->precision, conv, len);
		len = (int)ft_strlen(conv);
	}
	if (flags->width > len)
	{
		if (flags->precision || flags->dot)
			flags->zero = none;
		conv = define_align_width(conv, flags, len);
	}
	return (conv);
}
