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

/*void	ft_printf_i(va_list arg)
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
}*/

char	*ft_printf_i(va_list arg, flags_list *flags)
{
	char	*conv_i;
	char	*temp;
	int		i;

	printf("\nflags->i = %i\n", flags->width);
	i = va_arg(arg, int);
	conv_i = ft_itoa(i);
	if (!conv_i)
		return (NULL);
	if (flags->width)
	{
		temp = ft_substr(conv_i, 0, flags->width);
		free(conv_i);
		conv_i = temp;
		printf("\ncut string ? = %s\n", conv_i);
	}
	return (conv_i);
}
