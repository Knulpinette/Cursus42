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

typedef enum e_align
{
	left = 1,
	right,
}				t_align;

typedef enum e_flags
{
	none,
	zero,
	dot,
	minus,
	wildcard,
}				t_e_flags;

typedef struct s_flags
{
	int		zero;
	int		minus;
	int		width;
	int		arg_width;
	int		dot;
	int		precision;
	int		arg_precision;
	char	type;
}				t_flags;

t_flags			*ft_get_flags(const char *s, va_list arg);
char			*define_align_width(char *conv, t_flags *flags, int len);
char			*align_nb_precision(int precision, char *conv, int len);

#endif
