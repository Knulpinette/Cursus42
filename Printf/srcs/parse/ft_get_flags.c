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

/*
** 🦕
** function : get_flags
** returns : a t_flags with all the flags
** The t_flags is set in ft_printf_parse.h.
** 🦕
*/

/*
** function : i_am_flag
** checks for flags -/0/./*
** returns : an int whose name is the value associated to the proper flag
** Those values are set in an enum in ft_printf_parse.h.
*/

int			ft_i_am_flag(char c)
{
	if (c == '-')
		return (minus);
	if (c == '0')
		return (zero);
	if (c == '.')
		return (dot);
	if (c == '*')
		return (wildcard);
	return (none);
}

/*
** function : get_width
** returns : a pointer to the char we're at after parsing through the
** width segment.
** We get the width value if it's set in the string (digit), if it's not
** (wildcard), we go retrieve it at the end.
** Special case : if the retrieved arg at the end is negative, the minus
** is counted separately as if it was a flag and the width number is set
** to its positive value.
*/

const char	*ft_get_width(const char *s, t_flags **flags, va_list arg)
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
			flags[0]->width = -(flags[0]->width);
		}
	}
	return (s);
}

/*
** function : get_precision
** returns : a pointer to the char we're at after parsing through the
** precision segment.
** As for the width, we get the value either in the string (digit) or in
** the variadic argument's list.
** Special case : if there is only a dot, this info needs to be saved as
** it will be important in the conversion functions using precision.
*/

const char	*ft_get_precision(const char *s, t_flags **flags, va_list arg)
{
	if (ft_i_am_flag(*s) == dot)
	{
		flags[0]->dot = dot;
		if (!ft_i_am_conversion(*(s + 1)))
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

/*
** function : core_get_flags
** returns : a t_flags with all the flags
** First we get the '0' and the '-' as they are the first step.
** Then we get the width.
** Then the precision.
** Then the character indicating the type of conversion required for
** this argument.
*/

t_flags	*ft_get_flags(const char *s, va_list arg)
{
	t_flags	*flags;

	flags = (t_flags *)ft_calloc(sizeof(t_flags), 1);
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
