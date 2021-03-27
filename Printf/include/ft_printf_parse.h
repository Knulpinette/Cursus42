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

typedef enum	align_enum {
	left = 1,
	right,
}				align;

typedef enum	flag_enum {
	none,
	zero,
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
char		*define_align_width(char *conv, flags_list *flags, int len);
char		*align_nb_precision(int precision, char *conv, int len);

#endif


