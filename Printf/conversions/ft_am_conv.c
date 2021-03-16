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
** function : am_conv
** This function checks if the given character requires a conversion.
** It returns the given character if it fits : c/s/p/d/i/u/x/X/%/.
** 🦕
*/

char		ft_i_am_conversion(char c)
{
	char	*charset;
	int		i;

	charset = "cspdiuxX";
	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (c);
		i++;
	}
	return (0);
}

char		ft_is_special(const char *s) // change to return data_type after %+something
{
	int	i;

	i = 0;
	while (s[i++]) // théoriquement '%'
	{
		//printf("\ns[i] = %c", s[i]);
		if ((s[i] == '*' && s[i - 1] != '*') || ft_isdigit(s[i]) || (s[i] == '.' && s[i - 1] != '.'))
			i++;
		//printf("\ns[i] after 1 = %c", s[i]);
		if ((s[i] == '-' || s[i] == '+') && s[i - 1] != '-' && s[i - 2] != '+')
			i++;
		//printf("\ns[i] after 2 = %c", s[i]);
		if (ft_i_am_conversion(s[i]))
			return (s[i]);
	}
	return 0;
}

char		ft_am_conv(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_i_am_conversion(s[i]))
			return (s[i]);
		i++;
	}
	return (0);
}
