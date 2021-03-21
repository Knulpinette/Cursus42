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

#include "../../include/ft_printf.h"

int	ft_i_am_flag(char c)
{
	if (c == '-')
		return minus;
	if (c == '0')
		return zero;
	if (c == '.')
		return dot;
	if (c == '*')
		return wildcard;
	return 0;
}

int	ft_i_am_wildcard(char c)
{
	if (c == '*')
		return wildcard;
	return 0;
}	

int	ft_i_am_zero(char c)
{
	if (c == '0')
		return zero;
	return 0;
}

int	ft_i_am_dot(char c)
{
	if (c == '.')
		return dot;
	return 0;
}

int	ft_i_am_minus(char c)
{
	if (c == '-')
		return minus;
	return 0;
}
