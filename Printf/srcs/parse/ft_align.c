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

/*
** 🦕
** function : align_if_width_or_precision
** return : the new converted string.
** 🦕
*/

/*
** function : align_if_number_with_precision
** return : the new converted string
** -> Precision acts differently with numbers and strings.
** With numbers, precision acts like width + flag 0. It
** aligns everything to the right and and if precision is
** bigger than the actual size of the number, it fill the
** space in front of it with 0.
** Special case : If it's a negative number, it will write
** the minus, and then fill that space up with zeroes and
** the actual number. (why we use neg as a variable)
**
** FOR FUTURE REFERENCE : if this function doesn't comply
** with normV3, don't forget to add the -1 in the while loop
** for conv[len] && temp[precision] in the other while loop.
*/

char	*align_nb_precision(int precision, char *conv, int len)
{
	char	*temp;
	int		neg;

	neg = no;
	if (conv[0] == '-')
	{
		precision = precision + 1;
		neg = yes;
	}
	temp = (char *)malloc(sizeof(char) * precision + 1);
	if (!temp)
		return (NULL);
	temp[precision] = '\0';
	while (len-- > neg)
	{
		temp[precision - 1] = conv[len];
		precision--;
	}
	free(conv);
	while (precision-- > neg)
		temp[precision] = '0';
	if (neg)
		temp[0] = '-';
	conv = temp;
	return (conv);
}

/*
** function : left_align_width
** return : the new converted string.
** This function takes its cue if there is a flags->minus
** and align the converted argument to the left while
** padding the rest of the space with ' '.
*/

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

/*
** function : zero_align_width
** return : nothing.
** This function is an extension of ft_align_right.
** If there is a zero flag, it will fill up the extra
** space with 0.
** Special case : if the conversion type is 'd' or 'i'
** and the number is negative, we need to change -1101 to 01101.
** The '-' will be added all the way to the left.
*/

void	zero_align(char **temp, char **conv, int len, t_flags *flags)
{
	int	neg;

	neg = no;
	if (conv[0][len] = '-' && !(flags->type == 'u') \
	&& !(flags->type == 'x') && !(flags->type == 'X'))
	{
		neg = yes;
		temp[0][flags->width] = '0';
	}
	while (flags->width > 0)
	{
		temp[0][flags->width - 1] = '0';
		flags->width--;
	}
	if (neg == yes)
		temp[0][0] = '-';
}

/*
** function : right_align_width
** return : the new converted string.
** This function is the default align if there is width.
** It will align the converted argument to the right while
** padding the rest of the space with ' ', unless there is
** a zero flag, in which case it passes the work to function
** zero_align.
*/

char	*right_align(t_flags *flags, char *conv, int len, char *temp)
{
	temp[flags->width] = '\0';
	while (len > 0)
	{
		temp[flags->width - 1] = conv[len - 1];
		len--;
		flags->width--;
	}
	if (flags->zero)
		zero_align(&temp, &conv, len, flags);
	else
	{
		while (flags->width > 0)
		{
			temp[flags->width - 1] = ' ';
			flags->width--;
		}
	}
	free(conv);
	return (temp);
}

/*
** function : define_align_width
** return : the new converted string.
** This function allocates the proper space for the width
** then it decides if it will be left or right align depending
** on if there is a '-' flag or not.
*/

char	*define_align_width(char *conv, t_flags *flags, int len)
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
