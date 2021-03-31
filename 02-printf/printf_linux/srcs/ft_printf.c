/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
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
** function : ft_printf
** returns : total count of printed characters.
** 1. Print the string.
** 2. If we encounter %, get the argument.
**    First we get the number of character from % to the conversion character
**    so we know how long the segment is and start the new loop in the right
**    spot in ft_printf.
**    Then we send the argument list to get_arg function where we will:
**		-> 1. Parse through that portion of string and get the according flags.
**		-> 2. Send the argument to the right conversion function depending on
**			  its conversion type and return a string.
**		-> 3. Print the returned string.
**		-> 4. Return the count of characters printed for that argument.
** 3. We loop all over until the end - where we free the variadic list of arg !
** 🦕
*/

int		ft_printf(const char *s, ...)
{
	const char	*original_s;
	va_list		arg;
	char		*print;
	int			len_arg;
	int			count;

	count = 0;
	va_start(arg, s);
	while (*s)
	{
		original_s = s;
		while (*s && *s != '%')
			s++;
		write(1, original_s, (s - original_s));
		count = count + (s - original_s);
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
