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

typedef union 	data {
	char			c;
	char			*s;
	void			*p;
	double			d;
	int				i;
	unsigned int	u;
	int				x;
	int				X;
}				data_type;

char	ft_am_conv(const char *s);
char	ft_i_am_conversion(char c);
char	ft_i_am_flag(char c);
int		check_len_extra(const char *s);
void	ft_printf_c(va_list c);
void	ft_printf_s(va_list s);
char	*ft_printf_p(void *p);
char	*ft_printf_d(double d);
void	ft_printf_i(va_list i);
char	*ft_printf_u(unsigned int u);
char	*ft_printf_x(int x);
char	*ft_printf_X(int X);

#endif
