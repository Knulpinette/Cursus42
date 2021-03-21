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

char		*ft_get_arg(va_list arg, const char *s)
{
	flags_list	*flags;
	char	*arg_str;
	
	flags = ft_get_flags(s + 1, arg); // Important + 1 pour éviter %
	if (!flags)
		return (NULL);
	if (flags->type == 'i')
		arg_str = ft_printf_i(arg, flags);
	if (flags->type == 'd')
		arg_str = ft_printf_d(arg, flags);
	if (flags->type == 'c')
		arg_str = ft_printf_c(arg, flags);
	if (flags->type == 's')
		arg_str = ft_printf_s(arg, flags);
	if (flags->type == 'u')
		arg_str = ft_printf_u(arg, flags);
	if (flags->type == 'x')
		arg_str = ft_printf_x(arg, flags);
	if (flags->type == 'X')
		arg_str = ft_printf_X(arg, flags);
	if (flags->type == 'p')
		arg_str = ft_printf_p(arg, flags);
	//UNDERSTAND SPECIAL CASE AND HOW TO HANDLE INFERIOR TO 0
	if (flags->type == '%')
		arg_str = ft_printf_pourcent();
	if (!arg_str)
		return (NULL);
	free(flags);
	return (arg_str);
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
			print = ft_get_arg(arg, s);
			if (!print)
				return (0);
			count = count + ft_print_str(print);
			free(print);
			s = s + len_arg;
		}
	}
	va_end(arg);
	return (count);
}
