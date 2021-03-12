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
	data_type	*arg_type;
	int			i;
	int			count;
	
	i = 0;
	while (--arg_count && s[i])
	{
		while (!(ft_am_conv(s + i)) && s[i])
		{
			ft_putchar_fd(s[i], 1);
			s++;
		}
		if (ft_am_conv(s + i))
		{
			count = check_len_extra(s + i + 1);
			type = ft_am_conv(s + i);
		}
		i = i + count + 1;
		arg_type = (data_type *)malloc(sizeof(data_type));
		if (!arg_type)
			return (0);
		//printf("\n%c\n", type);
		if (type == 'i')	
			ft_printf_i(arg);
		if (type == 'c')
		{
			arg_type->c = va_arg(arg, int);
			//printf("%c\n", arg_type->c);
		}
		if (type == 's')
		{
			arg_type->s = va_arg(arg, char *);
			//printf("%s\n", arg_type->s);
		}
		free(arg_type);
	}
	return (1);
}

int		ft_printf(const char *s, ...)
{
	va_list		arg;
	int			arg_count;
	
	arg_count = ft_count_arg(s) + 1; // + 1 to pre-decrement in the loop
	//printf("count = %i\n", arg_count);
	va_start(arg, s);
	ft_get_arg(arg, arg_count, s);
	va_end(arg);
	return (0);
}
