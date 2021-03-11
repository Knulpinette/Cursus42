/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:11:56 by osurcouf          #+#    #+#             */
/*   Updated: 2021/03/11 11:11:57 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** 🦕
** function : count_arg
** This function counts the number of variadic arguments given to ft_printf.
** If it finds '%', it will check the next character. If that character
** requires a conversion, it will increment an int <count> to the exception
** that this character is '%'.
** 🦕
*/

int		ft_count_arg(const char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%' && (ft_i_am_conversion(s[i + 1]) && s[i + 1] != '%'))
			count++;
		i++;
	}
	return (count);
}
