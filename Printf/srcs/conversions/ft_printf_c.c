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

/*
** 🦕
** function : case_c
** returns : the number of characters printed in the converted string of
** the argument (a character).
** 🦕
*/

/*
** function : convert_c
** returns : a character converted in a string.
** First, we need to typecast the argument given as an int into a char.
** It's a specificity of variadic arguments, char are read as ints.
** Then we handle the special case where char = '\0' and set the appropriate
** variables so that the function processes the cases as it should. If there is
** width involved, we also need to set *align so that the printer knows how to
** handle the string it is getting.
** No need to handle precision since it's not used with the c conversion.
*/

char	*convert_c(va_list arg, t_flags *flags, int *char_null, int *align)
{
	char *conv;

	conv = (char *)malloc(sizeof(char) * 2);
	if (!conv)
		return (NULL);
	conv[0] = (char)va_arg(arg, int);
	conv[1] = '\0';
	if (conv[0] == '\0')
	{
		*char_null = yes;
		*align = right;
	}
	if (flags->width > 1)
	{
		if (char_null && flags->minus)
			*align = left;
		flags->zero = none;
		conv = define_align_width(conv, flags, 1);
	}
	return (conv);
}

/*
** function : case_c
** returns : the number of printed characters.
** We initialise the variables that will be needed to know which special case
** we're dealing with when we print the converted string. They will be modified
** directly in the convert_c function. If char_null = yes, we want to go to the
** special printer. If not, proceed as with the other conversions.
** Attention : free the flags.
*/

int		case_c(va_list arg, t_flags *flags, int count)
{
	int		align;
	int		char_null;
	char	*arg_str;

	align = no;
	char_null = no;
	arg_str = convert_c(arg, flags, &char_null, &align);
	if (!arg_str)
		return (-1);
	free(flags);
	if (char_null == yes)
		return (count + ft_print_c_null(arg_str, &align));
	return (count + ft_print_arg(arg_str));
}
