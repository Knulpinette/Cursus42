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

#include "ft_printf.h"

/*
** 🦕
*/

int		ft_get_arg(va_list arg, int arg_count, const char *s)
{
	char		type;
//	char		*arg_array[arg_count];
	int			i;
	int			count;
	
	i = 0;
	while (--arg_count && s[i]) // if I use a variable "up" => do up ++, not --arg_count
	{
		while (s[i] && s[i] != '%') // write string
			ft_putchar_fd(s[i++], 1);
		if (ft_am_conv(s + i)) //initialise needed variables
		{
			type = ft_am_conv(s + i); // what datatype we're dealing with
			count = check_len_extra(s + i + 1); // where i will have to be at the next loop (can goo at the end to save lines)
			i = i + count + 1; // new value of i
		}
		if (type == 'i')	
			ft_printf_i(arg);
		if (type == 'c')
			ft_printf_c(arg);
		if (type == 's')
			ft_printf_s(arg);
	}
	//handle width when printing here ? find out how to print from here ?
	return (arg_count);
}

// FIGURE OUT HOW TO RETURN ERROR WHEN WRONG NUMBER OF ARGUMENTS !

int		ft_printf(const char *s, ...)
{
	va_list		arg;
	int			arg_count;
	
	arg_count = ft_count_arg(s) + 1; // + 1 to pre-decrement in the loop
	//printf("count = %i\n", arg_count);
	va_start(arg, s);
	ft_get_arg(arg, arg_count, s);
	va_end(arg);
	if (arg_count == 1) // print line without arguments
		while (*s)
			ft_putchar_fd(*(s)++, 1);
	return (0);
}
