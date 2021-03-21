/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pourcent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 21:07:45 by osurcouf          #+#    #+#             */
/*   Updated: 2021/03/20 21:07:46 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

char	*ft_printf_pourcent()
{
	char	*arg_str;

	arg_str = (char *)malloc(sizeof(char) * 2);
	arg_str[0] = '%';
	arg_str[1] = '\0';
	return (arg_str);
}
