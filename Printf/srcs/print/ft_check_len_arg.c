/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_len_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 20:32:20 by osurcouf          #+#    #+#             */
/*   Updated: 2021/03/16 20:32:22 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int			ft_check_len_arg(const char *s) // change into calculating from % to charset
{
	int	len;

	len = 1; // counts '%'
	while (*s) 
	{
		if (ft_i_am_conversion(*s))
			return (len);
		s++;
		len++;
	}
	return (0);
}
