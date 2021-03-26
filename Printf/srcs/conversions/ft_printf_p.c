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

int		handle_zeroes(char *str)
{
	int count;

	count = 0;
	while (*str == '0')
	{
		count++;
		str++;
	}
	return (count);
}

char	*ft_putnbr_ptr(unsigned long l_nb, char *base, int size, int l, char *str)
{
	char	*temp;
	int		count;

	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = base[l_nb % l];
		l_nb = l_nb / l;
		size--;
	}
	count = handle_zeroes(str);
	if (!count)
	{
		temp = ft_strjoin("0x", str);
		free(str);
		str = temp;
	}
	if (count)
	{
		temp = ft_strjoin("0x", (str + count));
		free(str);
		str = temp;
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
	conv = (char *)ft_calloc(sizeof(char), size + 1);
	if (!(conv))
		return (NULL);
	conv = ft_putnbr_ptr(l_nb, base, size, l, conv);
	return (conv);
}

static char	*system_null()
{
	char	*null;

	#if __APPLE__
		null = ft_strdup("0x0");
	#else
		null = ft_strdup("(nil)");
	#endif
	return (null);
}

char	*ft_printf_p(va_list arg, flags_list *flags)
{
    unsigned long	x;
    char 			*conv;
	int				len;

	x = (unsigned long) va_arg(arg, void *);
	if (!x)
		conv = system_null();
	else
		conv = ft_itoa_convert_ptr(x, "0123456789abcdef");
	if (!conv)
		return (NULL);
	len = (int)ft_strlen(conv);
	if (flags->width > len)
	{
		flags->zero = 0;
		conv = define_align_width(conv, flags, len);
	}
    return (conv);
}

