/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 20:54:27 by osurcouf          #+#    #+#             */
/*   Updated: 2021/03/16 20:54:28 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

flags_list	*ft_get_flags(const char *s, va_list arg)
{
	flags_list	*flags;
	int			i;

	flags = (flags_list *)malloc(sizeof(flags_list) * 1);
	if (!flags)
		return (NULL);
	i = 0;
	while (!ft_i_am_conversion(s[i]))
	{
		if (ft_i_am_wildcard(s[i]))
		{
			flags->width = va_arg(arg, int);
			printf("\nis wildcard %i\n", flags->width);
		}
		i++;
	}
	return (flags);
}