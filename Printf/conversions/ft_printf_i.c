/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:33:56 by osurcouf          #+#    #+#             */
/*   Updated: 2021/03/12 13:33:57 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_printf_i(va_list arg)
{
	char	*temp;
	int		i;

	i = va_arg(arg, int);
	temp = ft_itoa(i);
	if (!temp)
		return ;
	ft_putstr_fd(temp, 1);
	free(temp);
	return ;
}

/*char	*ft_printf_i(va_list arg)
{
	char	*conv_i;
	int		i;

	i = va_arg(arg, int);
	conv_i = ft_itoa(i);
	if (!conv_i)
		return (NULL);
	return (conv_i);
}*/
