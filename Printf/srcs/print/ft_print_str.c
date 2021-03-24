/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:32:58 by osurcouf          #+#    #+#             */
/*   Updated: 2021/03/20 19:32:59 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_print_str(char *print)
{
	char	*end_print;

	end_print = print;
	while (*end_print)
		end_print++;
	write(1, print, (end_print - print));
	free(print);
	return (end_print - print);
}