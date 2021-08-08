/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 13:59:51 by osurcouf          #+#    #+#             */
/*   Updated: 2021/08/04 13:59:52 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	error(int error)
{
	if (error == NOT_NUMBER)
		ft_putstr_fd("Error\nOne of the arguments is not a number", 1);
	if (error == OVER_MAX)
		ft_putstr_fd("Error\nOne of the argument is over the int max", 1);
	if (error == OVER_MIN)
		ft_putstr_fd("Error\nOne of the arguments is under the int min", 1);
	exit(EXIT_FAILURE);
}

void check_input(char *argv)
{
	size_t i;

	i = 0;
	while (i < ft_strlen(argv))
	{
		if (argv[i] == '+' || argv[i] == '-')
			i++;
		if (!ft_isdigit(argv[i]))
			error(NOT_NUMBER);
		i++;
	}
	/*ft_putnbr_fd(INT_MAX, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(INT_MIN, 1);
	ft_putchar_fd('\n', 1);	
	if (ft_atoi(argv) > INT_MAX)
		error(OVER_MAX);
	if (ft_atoi(argv) < INT_MIN)
		error(OVER_MIN);*/
}

int	main(int argc, char **argv)
{
	int i;
	
	if (argc < 2)
		return (EXIT_SUCCESS);
	if (argc == 2)
		check_input(argv[1]);
    i = 1;
    while (i < argc)
    {
		if (ft_atoi(argv[i]))
		{
			ft_putstr_fd(argv[i], 1);
			ft_putchar_fd('\n', 1);
			//parse_arg(argv[i]);
		}
		else
			error(NOT_NUMBER);		
		i++;
    }
	return (EXIT_SUCCESS);
}
