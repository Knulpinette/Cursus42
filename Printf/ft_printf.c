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

char		*ft_get_arg(va_list arg, const char *s, int i, char **print)
{
	char	type;
	flags_list	*flags;
	char	*temp;
	char	*arg_str;
	
	flags = ft_get_flags(s, arg); // ICI va pas, trouver comment passer correctement l'arg
	type = ft_am_conv(s + i); // what datatype we're dealing with
	if (type == 'i')
		arg_str = ft_printf_i(arg, flags);
	if (type == 'c')
		arg_str = ft_printf_c(arg);
	if (type == 's')
		arg_str = ft_printf_s(arg);
	if (!arg_str)
		return (NULL);
	temp = ft_strjoin(*print, arg_str);
	if (!temp)
		return (NULL);
	free(arg_str);
	free(*print);
	*print = temp;
	//handle width when printing here ? find out how to print from here ?
	return (*print);
}

// FIGURE OUT HOW TO RETURN ERROR WHEN WRONG NUMBER OF ARGUMENTS !

int		ft_printf(const char *s, ...)
{
	va_list		arg;
	char		*print;
	char		*temp;
	char		*temp2;
	int			i;
	int			count;
	
	va_start(arg, s);
	print = ft_strdup("");
	if (!print)
		return (0);
	i = 0;
	while (s[i]) 
	{
		count = 0;
		while (s[i + count] && s[i + count] != '%') // save string
			count++;
		if (count)
		{
			temp = ft_substr(s, i, count);
			if (!temp)
				return (0);
			temp2 = ft_strjoin(print, temp);
			if (!temp2)
				return (0);
			free(temp);
			free(print);
			print = temp2;
			i = i + count;
		}
		if (s[i] == '%') //initialise needed variables
		{
			count = ft_check_len_arg(s + i + 1) + 1;
			ft_get_arg(arg, s, i, &print);
			i = i + count;
		}
	}
	va_end(arg);
	ft_putstr_fd(print, 1);
	count = ft_strlen(print);
	free(print);
	return (count);
}
