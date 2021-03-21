/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:33:43 by osurcouf          #+#    #+#             */
/*   Updated: 2021/03/12 13:33:45 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

char	*ft_putnbr_ptr(unsigned long l_nb, char *base, int size, int l, char *str)
{
	str[size - 1] = '\0';
	while (--size > 0)
	{
		str[size - 1] = base[l_nb % l];
		l_nb = l_nb / l;
	}
	return (str);
}

char	*ft_itoa_convert_ptr(unsigned long nb, char *base)
{
	unsigned long	l_nb;
	int				l;
	char			*conv;
	int				size;

	l = ft_strlen(base);
	l_nb = nb;
	size = 1;
	while ((nb / 10) != 0)
	{
		size++;
		nb = nb / 10;
	}
	conv = (char *)ft_calloc(sizeof(char), size);
	if (!(conv))
		return (NULL);
	conv = ft_putnbr_ptr(l_nb, base, size, l, conv);
	return (conv);
}

char	*ft_printf_p(va_list arg, flags_list *flags)
{
    unsigned long	x;
    char 			*conv;
	int				len;

	x = (unsigned long) va_arg(arg, void *);
	conv = ft_itoa_convert_ptr(x, "0123456789abcdef");
	conv[0] = '0';
	conv[1] = 'x';
	len = (int)ft_strlen(conv);
	if (flags->width > len)
	{
		flags->zero = 0;
		conv = define_align_width(conv, flags, len);
	}
    return (conv);
}

