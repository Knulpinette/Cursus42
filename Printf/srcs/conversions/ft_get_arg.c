/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 23:34:42 by osurcouf          #+#    #+#             */
/*   Updated: 2021/03/26 23:34:43 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

/*
** 🦕
** function : get_arg
** returns : count of printed characters
** Here, we get the argument after %.
** First we parse through the string to attribute the flags into a list.
** Then depending on the conversion character, we send the variadic argument
** list and the flags to the appropriate conversion function.
** 🦕
*/

int		ft_get_arg(va_list arg, const char *s, int count)
{
	flags_list	*flags;
	char		*arg_str;
	
	flags = ft_get_flags(s + 1, arg);
	if (!flags)
		return (-1);
	if (flags->type == 'i' || flags->type == 'd')
		arg_str = convert_i(arg, flags);
	if (flags->type == 'c')
		return (case_c(arg, flags, count));
	if (flags->type == 's')
		arg_str = convert_s(arg, flags);
	if (flags->type == 'u')
		arg_str = convert_u(arg, flags);
	if (flags->type == 'x' || flags->type == 'X')
		arg_str = convert_x(arg, flags);
	if (flags->type == 'p')
		arg_str = convert_p(arg, flags);
	if (flags->type == '%')
		arg_str = convert_pourcent();
	if (!arg_str)
		return (-1);
	free(flags);
	return (count + ft_print_str(arg_str));
}

/*
** function : i_am_conversion
** This function checks if the given character requires a conversion.
** It returns the given character if it fits : c/s/p/d/i/u/x/X/%/.
*/

char	ft_i_am_conversion(char c)
{
	char	*charset;
	int		i;

	charset = "cspdiuxX%";
	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (c);
		i++;
	}
	return (0);
}
