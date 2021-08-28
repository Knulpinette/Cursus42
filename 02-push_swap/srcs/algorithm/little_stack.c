/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_version.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:34:19 by osurcouf          #+#    #+#             */
/*   Updated: 2021/08/10 18:34:20 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;
	int		min;
	int		max;

	first = *stack_a;
	second = (*stack_a)->next;
	min = stack_min_value(*stack_a);
	max = stack_max_value(*stack_a);
	while (!stack_is_sorted(stack_a))
	{
		if (first->nb == max && second->nb == min)
			do_action(ROTATE_A, stack_a, NULL);
		else if (first->nb != min && second->nb == max)
			do_action(REVERSE_ROTATE_A, stack_a, NULL);
		else
			do_action(SWAP_A, stack_a, NULL);
	}
}

static void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	minimum;

	minimum = stack_min_value(*stack_a);
	while (stack_size(*stack_a) > 3)
		push_value(MINIMUM, PUSH_B, stack_a, stack_b);
	if (!stack_is_sorted(stack_a))
		sort_3(stack_a);
	while ((*stack_a)->nb != minimum)
		do_action(PUSH_A, stack_a, stack_b);
}

void	sort_little_stack(int argc, t_stack **stack_a, t_stack **stack_b)
{
	if (argc <= 3)
		sort_3(stack_a);
	else
		sort_5(stack_a, stack_b);
}
