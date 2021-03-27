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
** function : TO DO + shorten and organise
** 🦕
*/

char	*ft_putnbr_base_x(long int l_nb, char *base, int size, int l, char *str)
{
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = base[l_nb % l];
		l_nb = l_nb / l;
		size--;
	}
	return (str);
}

char	*ft_itoa_convert_x(unsigned int nb, char *base)
{
	unsigned long	l_nb;
	unsigned int	l;
	char			*conv;
	unsigned int	size;

	l = ft_strlen(base);
	l_nb = nb;
	size = 1;
	if (nb < 0)
		size++;
	while ((nb / l) != 0)
	{
		size++;
		nb = nb / l;
	}
	conv = (char *)ft_calloc(sizeof(char), size + 1);
	if (!(conv))
		return (NULL);
	conv = ft_putnbr_base_x(l_nb, base, size, l, conv);
	return (conv);
}


char	*convert_x(va_list arg, flags_list *flags)
{	
	char	*conv;
	int		i;
	int		len;
	
	i = va_arg(arg, int);
	if (flags->type == 'x')
		conv = ft_itoa_convert_x(i, "0123456789abcdef");
	if (flags->type == 'X')
		conv = ft_itoa_convert_x(i, "0123456789ABCDEF");
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
