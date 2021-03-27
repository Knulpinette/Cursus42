/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:34:05 by osurcouf          #+#    #+#             */
/*   Updated: 2021/03/12 15:00:26 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

/*
** 🦕
** function : convert_x
** return : the given int converted in hexadecimal, into a string.
** -> Handles both x and X types.
** 🦕
*/

/*
** function : handle_width_and_precision
** Modifies the values directly in the other function
** -> that's why it deals with **pointers.
** Special case : if there is width AND precision, the function will
** 				  ignore any flag '0'.
*/

static void	handle_w_and_p(char **conv, t_flags **flags, int *len)
{
	if ((flags[0]->precision + 1) > *len)
	{
		*conv = align_nb_precision(flags[0]->precision, *conv, *len);
		*len = (int)ft_strlen(*conv);
	}
	if (flags[0]->width > *len)
	{
		if (flags[0]->precision || flags[0]->dot)
			flags[0]->zero = 0;
		*conv = define_align_width(*conv, flags[0], *len);
	}
}

/*
** function : convert_x
** return : the given int converted in hexadecimal, into a string.
** 1. Converts the given unsigned int into the proper hexadecimal base.
** 2. Sends the data to the width and precision function.
** Special case : If the given int is 0, + precision is '.' or '.0'
**     			  AND there is width, the function returns a string '\0'.
**				  Else it creates a freeable empty string.
*/

char		*convert_x(va_list arg, t_flags *flags)
{
	char	*conv;
	int		len;

	if (flags->type == 'x')
		conv = ft_itoa_base(va_arg(arg, unsigned int), "0123456789abcdef");
	if (flags->type == 'X')
		conv = ft_itoa_base(va_arg(arg, unsigned int), "0123456789ABCDEF");
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
	handle_w_and_p(&conv, &flags, &len);
	return (conv);
}
