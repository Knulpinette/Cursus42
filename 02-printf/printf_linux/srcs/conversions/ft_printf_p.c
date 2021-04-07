/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:33:43 by osurcouf          #+#    #+#             */
/*   Updated: 2021/03/12 13:33:45 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

/*
** 🦕
** function : convert_p
** return : the adress of a pointer converted into an hexadecimal string.
** 1. A pointer adress (void *) is an unsigned long int.
** 2. If that adress is null, we need to return the system null.
** 3. Else, we convert the adress into hexadecimal and add '0x' as
**    a prefix.
** 4. We handle the width - while ignoring any '0' flag.
** 🦕
*/

static char	*system_null(void)
{
	char	*null;
	
	#if __APPLE__
		null = ft_strdup("0x0");
	#else
		null = ft_strdup("(nil)");
	#endif
	return (null);
}

char	*convert_p(va_list arg, t_flags *flags)
{
	unsigned long	x;
	char			*conv;
	char			*temp;
	int				len;

	x = (unsigned long)va_arg(arg, void *);
	if (!x)
		conv = system_null();
	else
	{
		temp = ft_itoa_base(x, "0123456789abcdef");
		if (!temp)
			return (NULL);
		conv = ft_strjoin("0x", temp);
		free(temp);
	}
	if (!conv)
		return (NULL);
	len = (int)ft_strlen(conv);
	if (flags->width > len)
	{
		flags->zero = none;
		conv = define_align_width(conv, flags, len);
	}
	return (conv);
}
