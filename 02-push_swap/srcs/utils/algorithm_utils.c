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

/*
** action = PUSH_A or PUSH_B
*/

static t_stack	**initialize_values(t_actions action, t_stack **stack, int *rev_rotate, int *rotate)
{
	if (action == PUSH_B)
	{
		*rev_rotate = REVERSE_ROTATE_A;
		*rotate = ROTATE_A;
		return (stack);
	}
	else
	{
		*rev_rotate = REVERSE_ROTATE_B;
		*rotate = ROTATE_B;
		return (stack);
	}
}

void	push_minimum(t_actions action, t_stack **stack_a, t_stack **stack_b)
{
	t_stack **stack;
	int	minimum;
	int	reverse_rotate;
	int	rotate;

	if (action == PUSH_B)
		stack = initialize_values(action, stack_a, &reverse_rotate, &rotate);
	else
		stack = initialize_values(action, stack_b, &reverse_rotate, &rotate);
	minimum = stack_min_value(*stack);
	while ((*stack)->nb != minimum)
	{
		if ((*stack)->nb != minimum && (*stack)->next->nb != minimum)
			do_action(reverse_rotate, stack_a, stack_b);
		else
			do_action(rotate, stack_a, stack_b);
	}
	do_action (action, stack_a, stack_b);
}

void	push_maximum(t_actions action, t_stack **stack_a, t_stack **stack_b)
{
	t_stack **stack;
	int	maximum;
	int	reverse_rotate;
	int	rotate;

	if (action == PUSH_B)
		stack = initialize_values(action, stack_a, &reverse_rotate, &rotate);
	else
		stack = initialize_values(action, stack_b, &reverse_rotate, &rotate);
	maximum = stack_max_value(*stack);
	while ((*stack)->nb != maximum)
	{
		if ((*stack)->nb != maximum && (*stack)->next->nb != maximum)
			do_action(reverse_rotate, stack_a, stack_b);
		else
			do_action(rotate, stack_a, stack_b);
	}
	do_action (action, stack_a, stack_b);
}
