/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 09:52:55 by osurcouf          #+#    #+#             */
/*   Updated: 2020/12/17 17:07:25 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		base_is_valid(char *base, int l)
{
	int i;
	int j;

	i = 0;
	j = i + 1;
	if (base[i] == '\0' || l == 1)
		return (0);
	while (base[i] != '\0')
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*ft_putnbr_base(long int l_nb, char *base, int size, int l, char *str)
{
	int	check_n;

	check_n = 0;
	if (l_nb < 0)
	{
		check_n++;
		l_nb = -l_nb;
	}
	str[size - 1] = '\0';
	while (--size > 0)
	{
		str[size - 1] = base[l_nb % l];
		l_nb = l_nb / l;
	}
	if (check_n == 1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa_convert_base(int nb, char *base)
{
	long int	l_nb;
	int			l;
	char		*conv;
	int			size;

	l = ft_strlen(base);
	l_nb = nb;
	size = 2;
	if (nb < 0)
		size++;
	while ((nb / 10) != 0)
	{
		size++;
		nb = nb / 10;
	}
	conv = (char *)ft_calloc(sizeof(char), size);
	if (!(conv))
		return (NULL);
	if (base_is_valid(base, l))
		conv = ft_putnbr_base(l_nb, base, size, l, conv);
	return (conv);
}
