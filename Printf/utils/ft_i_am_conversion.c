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

#include "../ft_printf.h"

/*
** 🦕
** function : i_am_conversion
** This function checks if the given character requires a conversion.
** It returns 1 if the given character fits : c/s/p/d/i/u/x/X/%/.
** 🦕
*/

int		ft_i_am_conversion(char c)
{
	char	*charset;
	int		i;

	charset = "cspdiuxX%";
	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}
