/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_limits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:50:21 by osurcouf          #+#    #+#             */
/*   Updated: 2021/08/19 11:50:23 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_min_value(t_stack *stack)
{
	int	minimum;

	minimum = stack->nb;
	while (stack)
	{
		if (stack->nb < minimum)
			minimum = stack->nb;
		stack = stack->next;
	}
	return (minimum);
}

int	stack_max_value(t_stack *stack)
{
	int	maximum;

	maximum = stack->nb;
	while (stack)
	{
		if (stack->nb > maximum)
			maximum = stack->nb;
		stack = stack->next;
	}
	return (maximum);
}
