/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 13:30:47 by osurcouf          #+#    #+#             */
/*   Updated: 2021/08/09 13:30:48 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(int error, t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a)
		stack_clear(stack_a);
	if (stack_b)
		stack_clear(stack_b);
	if (error == NOT_NUMBER)
		ft_putstr_fd("Error\nOne of the arguments is not a number", 1);
	if (error == OVER_MAX)
		ft_putstr_fd("Error\nOne of the argument is over the int max", 1);
	if (error == OVER_MIN)
		ft_putstr_fd("Error\nOne of the arguments is under the int min", 1);
	if (error == MEMORY_ALLOC)
		ft_putstr_fd("Error\nMemory badly allocated !", 1);
	if (error == DUPLICATE)
		ft_putstr_fd("Error\nThere's a duplicate number in your input.", 1);
	exit(EXIT_FAILURE);
}
