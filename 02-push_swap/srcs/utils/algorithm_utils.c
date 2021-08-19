/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:48:34 by osurcouf          #+#    #+#             */
/*   Updated: 2021/08/19 12:48:36 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_minimum(t_stack **stack_a, t_stack **stack_b)
{
	int	minimum;

	minimum = stack_min_value(*stack_a);
	while ((*stack_a)->nb != minimum)
	{
		if ((*stack_a)->nb != minimum && (*stack_a)->next->nb != minimum)
			do_action(REVERSE_ROTATE_A, stack_a, NULL);
		else
			do_action(SWAP_A, stack_a, NULL);
	}
	push_b(stack_a, stack_b);
}
