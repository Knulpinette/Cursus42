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

#include "../../include/ft_printf.h"

char	*ft_printf_u(va_list arg, flags_list *flags)
{	
	char	*conv;
	int		i;
	int		len;

	i = va_arg(arg, int);
	if (i < 0)
	{
		conv = ft_strdup(" ");
		flags->width = flags->width + 1; // ?? not sure at all. Undefined behaviour ?
		flags->precision = flags->precision + 1; //?? same
	}
	else
		conv = ft_itoa(i);
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

