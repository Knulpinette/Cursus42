/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:08:00 by osurcouf          #+#    #+#             */
/*   Updated: 2021/03/12 14:08:02 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_printf_s(va_list arg)
{
	char	*conv;
	
	conv = va_arg(arg, char *);
	ft_putstr_fd(conv, 1);
	return ;
}

/*char	*ft_printf_s(va_list arg)
{
	char	*temp;
	char	*conv;

	temp = va_arg(arg, char *);
	conv = ft_strdup(temp);
	free(temp);
	return(conv);
}*/

