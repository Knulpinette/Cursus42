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

int	ft_count_arg(const char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%' && (s[i + 1] != '%' && s[i + 1] != '\0'))
			count++;
		i++;
	}
	return (count); 
}

//int		ft_check_arg()

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		arg_count;
	int		cur_arg;
	int		original_ac;

	original_ac = ft_count_arg(s);
	arg_count = original_ac + 1;
	//printf("count = %i\n", arg_count);
	va_start(arg, s);
	// need to find out how to check for arg 
	//when there's not supposed to be any and return error
	while (--arg_count)
	{
		//if (ft_check_arg(,))
		//depending on what has been checked => expects a certain type of argt. 
		//=> return error if not the right type
		//in the meantime => argt
			cur_arg = va_arg(arg, int);
			if (!cur_arg)
			{
				ft_printf("Error : not the right number of arguments\n");
				return (-1);
			}
		//printf("cur_arg = %i\n", cur_arg);
	}
	if (arg_count == original_ac && !arg_count)
	{
		ft_putstr_fd((char *)s, 1);
		return (0);
	}
	va_end(arg);
	return (0);
}
