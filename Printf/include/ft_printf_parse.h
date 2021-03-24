/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:55:43 by osurcouf          #+#    #+#             */
/*   Updated: 2021/03/12 12:55:45 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PARSE_H
# define FT_PRINTF_PARSE_H

typedef enum	data_enum {
	string,
	argument,
}				data_type;

typedef enum	flag_enum {
	zero = 1,
	dot,
	minus,
	wildcard,
}				flags;

typedef struct	new_list {
	int		zero;
	int 	minus;
	int		width;
	int		arg_width;
	int		dot;
	int		precision;
	int		arg_precision;
	char	type;
}				flags_list;

flags_list	*ft_get_flags(const char *s, va_list arg);
int			ft_i_am_flag(char c);
int			ft_i_am_wildcard(char c);
int			ft_i_am_zero(char c);
int			ft_i_am_dot(char c);
int			ft_i_am_minus(char c);

#endif


