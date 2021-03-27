/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:32:58 by osurcouf          #+#    #+#             */
/*   Updated: 2021/03/20 19:32:59 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

/*
** 🦕
** function : printing_strings
** return : number of character printed
** This function prints the argument converted into a string and frees it.
** 🦕
*/

int	ft_print_str(char *print)
{
	char	*end_print;
	int		count;

	end_print = print;
	while (*end_print)
		end_print++;
	write(1, print, (end_print - print));
	count = end_print - print;
	free(print);
	return (count);
}

/*
** function : print_case_c_if_null
** return : number of character printed
** This function prints the argument converted into a string and frees it.
** It handles the special case of the c conversion where the given character
** is '\0'. It prints it separately and includes it in the count of printed
** characters even though it is not visible in the result.
** The variable align is set in the conversion function and indicates that
** there is a \0 aligned to the left, but also other empty characters to the
** right.
*/

int	ft_print_c_null(char *print, int *align)
{
	char	*end_print;
	int		count;
	char	null;

	null = '\0';
	end_print = print;
	if (!align)
	{
		write(1, &null, 1);
		return (1);
	}
	if (*align = left)
	{
		write(1, &null, 1);
		while (*end_print)
			end_print++;
		write(1, print, (end_print - print));
	}
	count = end_print - print + 1;
	free(print);
	return (count);
}

/*
** function : check_length_of_arg
** return : number of characters from % to i_am_conversion
** This function allows to set the cursor in the string to the right place
** for the next loop once it read an argument.
** Len is set to 1 to count the % character in the total since *(s+1) is sent
** from ft_printf.
*/

int	ft_check_len_arg(const char *s)
{
	int	len;

	len = 1;
	while (*s) 
	{
		if (ft_i_am_conversion(*s))
			return (len);
		s++;
		len++;
	}
	return (0);
}
