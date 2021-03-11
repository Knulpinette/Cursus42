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

/*
char	ft_extract_type_var(const char *s, int i)
{
	while (s[i])
	{
		if (s[i] == '%' && (s[i + 1] != '%' && s[i + 1] != '\0'))
			return (s[i + 1]);
		i++;
	}
	return (0);
}

//return LIST or the other thing that's equivalent
int		ft_convert(int	i)
{
	//int i;

	//i = 0;
	return (i);
}
*/

int		ft_printf(const char *s, ...)
{
	va_list	arg;
	int		arg_count;
	int		original_ac;
	//char	*cur_arg;
	int		test;
	
	original_ac = ft_count_arg(s);
	arg_count = original_ac + 1; // + 1 to pre-decrement in the loop
	//printf("count = %i\n", arg_count);
	va_start(arg, s);
	// need to find out how to check for arg 
	//when there's not supposed to be any and return error
	while (--arg_count)
	{
		//cur_arg = va_arg(arg, char *);
		test = va_arg(arg, int);
		printf("count = %i || cur_arg = %i\n", arg_count, test);
	}
	va_end(arg);
	if (arg_count == original_ac && !arg_count)
		ft_putstr_fd((char *)s, 1); //return 0;
	return (0);
}
