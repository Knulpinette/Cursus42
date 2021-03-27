/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversions.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:30:14 by osurcouf          #+#    #+#             */
/*   Updated: 2021/03/11 11:30:18 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_CONVERSIONS_H
# define FT_PRINTF_CONVERSIONS_H

#include "ft_printf_parse.h"

typedef enum	is_enum {
	no,
	yes,
}				is_or_not;

int		ft_get_arg(va_list arg, const char *s, int count);
char	ft_i_am_conversion(char c);
int		case_c(va_list arg, flags_list *flags, int count);
char	*convert_s(va_list s, flags_list *flags);
char	*convert_p(va_list p, flags_list *flags);
char	*convert_i(va_list d, flags_list *flags);
char	*convert_u(va_list u, flags_list *flags);
char	*convert_x(va_list x, flags_list *flags);
char	*convert_pourcent();

#endif
