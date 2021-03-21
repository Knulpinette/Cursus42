/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_am_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:32:51 by osurcouf          #+#    #+#             */
/*   Updated: 2021/03/11 11:32:53 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

/*
** 🦕
** function : am_conv
** This function checks if the given character requires a conversion.
** It returns the given character if it fits : c/s/p/d/i/u/x/X/%/.
** 🦕
*/

char		ft_i_am_conversion(char c)
{
	char	*charset;
	int		i;

	charset = "cspdiuxX%";
	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (c);
		i++;
	}
	return (0);
}
