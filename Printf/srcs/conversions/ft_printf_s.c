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

#include "../../include/ft_printf.h"

/*
** 🦕
** function : convert_s
** return : the string converted into a malloc'ed string.
** 1. If the string is null => return the system null.
** 2. If it's not, allocate the proper memory and proceed.
** 3. If precision is less than total length of the string,
**    it will troncate the string.
** 4. Then handle the width which will always have no flag 0 effect.
**
** NOTE FOR SELF : if need be, add again in if (flags->dot)
**             -> || (flags->precision < len && flags->precision)
** 🦕
*/

char	*convert_s(va_list arg, t_flags *flags)
{
	char	*temp;
	char	*verif;
	char	*conv;
	int		len;

	verif = va_arg(arg, char *);
	if (verif == NULL)
		conv = ft_strdup("(null)");
	else
		conv = ft_strdup(verif);
	len = ft_strlen(conv);
	if (flags->dot)
	{
		temp = ft_substr(conv, 0, flags->precision);
		free(conv);
		conv = temp;
		len = ft_strlen(conv);
	}
	if (flags->width > len)
	{
		flags->zero = none;
		conv = define_align_width(conv, flags, len);
	}
	return (conv);
}

/*
** FOR PERSONNAL REFERENCE
** static char	*system_null()
**{
** char *null;
**
**  #if __APPLE__
**		null = ft_strdup("0x0");
**	#else
**		null = ft_strdup("(null)");
**	#endif
** return null;
**}
*/
