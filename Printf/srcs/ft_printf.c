/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:00:59 by osurcouf          #+#    #+#             */
/*   Updated: 2021/03/10 19:01:01 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
** 🦕
*/

int		ft_get_arg(va_list arg, const char *s, int count)
{
	flags_list	*flags;
	char	*arg_str;
	
	flags = ft_get_flags(s + 1, arg); // Important + 1 pour éviter %
	if (!flags)
		return (-1);
	if (flags->type == 'i' || flags->type == 'd')
		arg_str = ft_printf_i(arg, flags);
	if (flags->type == 'c')
		arg_str = ft_printf_c(arg, flags, &count);
	if (flags->type == 's')
		arg_str = ft_printf_s(arg, flags);
	if (flags->type == 'u')
		arg_str = ft_printf_u(arg, flags);
	if (flags->type == 'x' || flags->type == 'X')
		arg_str = ft_printf_x(arg, flags);
	if (flags->type == 'p')
		arg_str = ft_printf_p(arg, flags);
	if (flags->type == '%')
		arg_str = ft_printf_pourcent();
	if (!arg_str)
		return (-1);
	free(flags);
	return (count + ft_print_str(arg_str));
}

int		ft_printf(const char *s, ...)
{
	va_list		arg;
	char		*print;
	int			len_arg;
	int			count;
	const char	*o_s;
	
	count = 0;
	va_start(arg, s);
	while (*s) 
	{
		o_s = s;
		while (*s && *s != '%')
			s++;
		write(1, o_s, (s - o_s));
		count = count + (s - o_s);
		if (*s == '%')
		{
			len_arg = ft_check_len_arg(s + 1) + 1;
			count = ft_get_arg(arg, s, count);
			s = s + len_arg;
		}
	}
	va_end(arg);
	return (count);
}
