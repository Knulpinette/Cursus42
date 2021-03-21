/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:08:00 by osurcouf          #+#    #+#             */
/*   Updated: 2021/03/12 14:08:02 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

char	*ft_printf_s(va_list arg, flags_list *flags)
{
	char	*temp;
	char	*conv;
	int		len;

	conv = ft_strdup(va_arg(arg, char *));
	len = ft_strlen(conv);
	if (flags->precision < len && flags->precision != 0)
	{
		temp = ft_substr(conv, 0, flags->precision);
		free(conv);
		conv = temp;
		len = ft_strlen(conv);
	}
	if (flags->width > len)
	{
		flags->zero = 0;
		conv = define_align_width(conv, flags, len);
	}
	return(conv);
}
