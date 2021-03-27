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
** function : TO DO + shorten and organise
** 🦕
*/

static char	*ft_putnbr_u(unsigned long nb, char *str, int size)
{
	str[size - 1] = '\0';
	while (--size > 0)
	{
		str[size - 1] = '0' + nb % 10;
		nb = nb / 10;
	}
	return (str);
}

static char		*ft_itoa_u(unsigned int n)
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
	return (ft_putnbr_u(nb, str, size));
}

char	*convert_u(va_list arg, flags_list *flags)
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
	if ((flags->precision + 1) > len)
	{
		conv = align_nb_precision(flags->precision, conv, len);
		len = (int)ft_strlen(conv);
	}
	if (flags->width > len)
	{
		if (flags->precision || flags->dot)
			flags->zero = 0;
		conv = define_align_width(conv, flags, len);
	}
	return (conv);
}

