/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 18:17:27 by osurcouf          #+#    #+#             */
/*   Updated: 2021/03/20 18:17:29 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

char	*align_nb_precision(int precision, char *conv, int len)
{
	char	*temp;
	int		neg;

	neg = 0;
	if (conv[0] == '-')
	{
		precision = precision + 1;
		neg = 1;
	}
	temp = (char *)malloc(sizeof(char) * precision + 1);
	if (!temp)
		return (NULL);
	temp[precision] = '\0';
	while (len-- > neg) // if need to extend function, do not forget conv[len - 1]
	{
		temp[precision - 1] = conv[len];
		precision--;
	}
	free(conv);
	while (precision-- > neg) // if need to extend function not forget temp[precision -1]
		temp[precision] = '0';
	if (neg)
		temp[0] = '-';
	conv = temp;
	return (conv);
}

char	*left_align(int width, char *conv, int len, char *temp)
{
	int		i;

	i = 0;
	while (i < len)
	{
		temp[i] = conv[i];
		i++;
	}
	free(conv);
	while (i < width)
	{
		temp[i] = ' ';
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

void	zero_align(char	**temp, int width, int i)
{
	while (width > 0)
	{
		temp[0][width - 1] = '0';
		width--;
	}
	if (i)
		temp[0][0] = '-';
}

char	*right_align(flags_list *flags, char *conv, int len, char *temp)
{
	int	i;

	i = 0;	
	temp[flags->width] = '\0';
	while (len > 0)
	{
		temp[flags->width - 1] = conv[len - 1];
		len--;
		flags->width--;
	}
	if (conv[0] = '-' && flags->zero && !(flags->type == 'u') \
	&& !(flags->type == 'x') && !(flags->type == 'X')) //-000 case in i
	{
		i = i + 1;
		temp[flags->width] = '0';
	}
	free(conv);
	if (flags->zero) // ZERO CASE
		zero_align(&temp, flags->width, i);
	else // DEFAULT CASE RIGHT ALIGN
	{
		while (flags->width > 0)
		{
			temp[flags->width - 1] = ' ';
			flags->width--;
		}
	}
	return (temp);
}

char	*define_align_width(char *conv, flags_list *flags, int len)
{
	char	*temp;
	
	temp = malloc(sizeof(int) * flags->width + 1);
	if (!temp)
		return (NULL);
	if (flags->minus)
		conv = left_align(flags->width, conv, len, temp);
	else
		conv = right_align(flags, conv, len, temp);
	return (conv);
}
