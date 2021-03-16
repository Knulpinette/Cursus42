/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:55:43 by osurcouf          #+#    #+#             */
/*   Updated: 2021/03/12 12:55:45 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FLAGS_H
# define FT_PRINTF_FLAGS_H

typedef struct	new_list {
	int	zero;
	int	dot;
	int	minus;
	int	wildcard;
	int	width;
	int	precision;
}				flags_list;

flags_list	*ft_get_flags(const char *s, va_list arg);
int			ft_i_am_flag(char c);
int			ft_i_am_wildcard(char c);
int			ft_i_am_zero(char c);
int			ft_i_am_dot(char c);
int			ft_i_am_minus(char c);

#endif


