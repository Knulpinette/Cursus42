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
** function : convert_i
** return : a integer converted into a string
** 1. We use itoa to convert the given argument into a string.
** 2. If there is only a '.' & the nb = 0 => cf special case 1.
** 3. We handle the precision if there's any.
** 4. We handle the width if there's any.
** Special case 1. If nb is 0, there is a '.' and a 0 value for precision,
**                 there's two different cases. If there's also a width,
**                 you return \0. If not, it's an empty freeable string.
** Special case 2. If there is a flag precision AND a flag width, any flag '0'
**                 will be ignored.
** 🦕
*/

static void	handle_w_and_p(char **conv, t_flags **flags, int *len)
{
	if (flags[0]->dot && (flags[0]->precision + 1) > *len)
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

char		*convert_i(va_list arg, t_flags *flags)
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
	handle_w_and_p(&conv, &flags, &len);
	return (conv);
}
