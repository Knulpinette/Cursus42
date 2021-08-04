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

# include "ft_printf_parse.h"

typedef enum e_no_yes
{
	no,
	yes,
}				t_yes_or_no;

int		ft_get_arg(va_list arg, const char *s, int count);
char	ft_i_am_conversion(char c);
int		case_c(va_list arg, t_flags *flags, int count);
char	*convert_s(va_list s, t_flags *flags);
char	*convert_p(va_list p, t_flags *flags);
char	*convert_i(va_list d, t_flags *flags);
char	*convert_u(va_list u, t_flags *flags);
char	*convert_x(va_list x, t_flags *flags);
char	*convert_pourcent(void);

#endif
