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
** function : convert_s
** return : the string converted into a malloc'ed string.
** 1. If the string is null => return the system null.
** 2. If it's not, allocate the proper memory and proceed.
** 3. If precision is less than total length of the string,
**    it will troncate the string.
** 4. Then handle the width which will always have no flag 0 effect.
** Special case : if precision is between 0 and 5 and the string is NULL,
** 				  it apparently prints nothing at all. Go figure.
**				-> cf handle_precision
** 🦕
*/

void	handle_precision(char **conv, t_flags **flags, int *len, char **verif)
{
	char	*temp;

	if (flags[0]->dot || (flags[0]->precision < *len && flags[0]->precision))
	{
		if (*verif == NULL && (flags[0]->precision == 1 \
		|| flags[0]->precision == 2 || flags[0]->precision == 3 \
		|| flags[0]->precision == 4 || flags[0]->precision == 5))
			flags[0]->precision = no;
		temp = ft_substr(*conv, 0, flags[0]->precision);
		free(*conv);
		*conv = temp;
		*len = ft_strlen(*conv);
	}
}

char	*convert_s(va_list arg, t_flags *flags)
{
	char	*verif;
	char	*conv;
	int		len;

	verif = va_arg(arg, char *);
	if (verif == NULL)
		conv = ft_strdup("(null)");
	else
		conv = ft_strdup(verif);
	len = ft_strlen(conv);
	handle_precision(&conv, &flags, &len, &verif);
	if (flags->width > len)
	{
		flags->zero = none;
		conv = define_align_width(conv, flags, len);
	}
	return (conv);
}
