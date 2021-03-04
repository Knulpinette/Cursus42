/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:51:56 by osurcouf          #+#    #+#             */
/*   Updated: 2021/02/18 14:51:59 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	char	a;

	a = (char)c;
	while (*str)
	{
		if (*str == a)
			return ((char *)str);
		str++;
	}
	if (c == '\0' && *str == '\0')
		return ((char *)str);
	return (0);
}
