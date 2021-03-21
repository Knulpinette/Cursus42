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

char	ft_am_conv(const char *s);
char	ft_i_am_conversion(char c);
char	*define_align_width(char *conv, flags_list *flags, int len);
char	*align_nb_precision(int precision, char *conv, int len);
char	*ft_printf_c(va_list c, flags_list *flags);
char	*ft_printf_s(va_list s, flags_list *flags);
char	*ft_printf_p(va_list p, flags_list *flags);
char	*ft_printf_d(va_list d, flags_list *flags);
char	*ft_printf_i(va_list i, flags_list *flags);
char	*ft_printf_u(va_list u, flags_list *flags);
char	*ft_printf_x(va_list x, flags_list *flags);
char	*ft_printf_X(va_list X, flags_list *flags);
char	*ft_itoa_convert_x(unsigned int nb, char *base);
char	*ft_putnbr_base_x(long int l_nb, char *base, int size, int l, char *str);
char	*ft_printf_pourcent();

#endif
