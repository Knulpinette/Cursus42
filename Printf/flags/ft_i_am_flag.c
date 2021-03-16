/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_am_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 20:28:17 by osurcouf          #+#    #+#             */
/*   Updated: 2021/03/16 20:28:19 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_i_am_flag(char c)
{
	char	*flagset;
	int		i;

	flagset = "-0.*";
	i = 0;
	while (flagset[i])
	{
		if (c == flagset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_i_am_wildcard(char c)
{
	if (c == '*')
		return 1;
	return 0;
}	

int	ft_i_am_zero(char c)
{
	if (c == '0')
		return 1;
	return 0;
}

int	ft_i_am_dot(char c)
{
	if (c == '.')
		return 1;
	return 0;
}

int	ft_i_am_minus(char c)
{
	if (c == '-')
		return 1;
	return 0;
}
