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

/*
** 🦕
** function : to DO + clean
** 🦕
*/

static char	*system_null()
{
	char	*null;

	#if __APPLE__
		null = ft_strdup("0x0");
	#else
		null = ft_strdup("(null)");
	#endif
	return (null);
}

char	*convert_s(va_list arg, flags_list *flags)
{
	char	*temp;
	char	*verif;
	char	*conv;
	int		len;

	verif = va_arg(arg, char *);
	if (verif == NULL)
		conv = system_null();
	else
		conv = ft_strdup(verif);
	len = ft_strlen(conv);
	if ((flags->precision < len && flags->precision) || flags->dot)
	{
		temp = ft_substr(conv, 0, flags->precision);
		free(conv);
		conv = temp;
		len = ft_strlen(conv);
	}
		if (flags->width > len)
	{
		flags->zero = none;
		conv = define_align_width(conv, flags, len);
	}
	return(conv);
}
