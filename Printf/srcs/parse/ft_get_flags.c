/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 20:54:27 by osurcouf          #+#    #+#             */
/*   Updated: 2021/03/16 20:54:28 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

const char	*ft_get_width(const char *s, flags_list **flags, va_list arg)
{
	if (ft_isdigit(*s) && *s != '0')
	{
		flags[0]->width = ft_atoi(s);
		while (ft_isdigit(*s))
			s++;
	}
	if (ft_i_am_flag(*s) == wildcard)
	{
		flags[0]->width = va_arg(arg, int);
		if (flags[0]->width < 0)
		{
			flags[0]->minus = minus;
			flags[0]->width = -flags[0]->width;
		}
	}
	return (s);
}

const char	*ft_get_precision(const char *s, flags_list **flags, va_list arg)
{
	if (ft_i_am_flag(*s) == dot)
	{
		flags[0]->dot = dot;
		if(!ft_i_am_conversion(*(s + 1)))
		{
			s++;
			if (ft_isdigit(*s))
			{
				flags[0]->precision = ft_atoi(s);
				while (ft_isdigit(*s))
					s++;
			}
			else if (ft_i_am_flag(*s) == wildcard)
				flags[0]->precision = va_arg(arg, int);
		}
	}
	return (s);
}

flags_list	*ft_get_flags(const char *s, va_list arg)
{
	flags_list	*flags;

	flags = (flags_list *)ft_calloc(sizeof(flags_list), 1);
	if (!flags)
		return (NULL);
	while (!ft_i_am_conversion(*s))
	{
		if (ft_i_am_flag(*s) == zero)
			flags->zero = zero;
		if (ft_i_am_flag(*s) == minus)
			flags->minus = minus;
		s = ft_get_width(s, &flags, arg);
		s = ft_get_precision(s, &flags, arg);
		if (!ft_i_am_conversion(*s))
			s++;
	}
	if (ft_i_am_conversion(*s))
		flags->type = *s;
	return (flags);
}