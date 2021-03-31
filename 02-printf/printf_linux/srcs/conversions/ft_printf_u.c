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

/*
** 🦕
** function : convert_u
** return : the given unsigned int converted into a string.
** 🦕
*/

/*
** function : unsigned_itoa
** Works exactly like the classic version of ft_itoa, but
** for an unsigned int !
*/

static char	*ft_itoa_u(unsigned int n)
{
	unsigned int		size;
	unsigned long int	nb;
	char				*str;

	nb = (long int)n;
	size = 2;
	while ((n / 10) != 0)
	{
		size++;
		n = n / 10;
	}
	str = (char *)ft_calloc(sizeof(char), size);
	if (!(str))
		return (NULL);
	str[size - 1] = '\0';
	while (--size > 0)
	{
		str[size - 1] = '0' + nb % 10;
		nb = nb / 10;
	}
	return (str);
}

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
		if (flags[0]->precision > 0 || (flags[0]->dot && !flags[0]->precision))
			flags[0]->zero = 0;
		*conv = define_align_width(*conv, flags[0], *len);
	}
}

/*
** function : convert_u
** return : the given unsigned int into a string.
** 1. Converts the given unsigned int into a string.
** 2. Sends the data to the width and precision function.
** Special case : If the given int is 0, + precision is '.' or '.0'
**     			  AND there is width, the function returns a string '\0'.
**				  Else it creates a freeable empty string.
*/

char		*convert_u(va_list arg, t_flags *flags)
{
	char			*conv;
	unsigned int	i;
	int				len;

	i = va_arg(arg, unsigned int);
	conv = ft_itoa_u(i);
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
