/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_version.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:34:25 by osurcouf          #+#    #+#             */
/*   Updated: 2021/08/10 18:34:26 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big_stack(t_stack **stack_a, t_stack **stack_b)
{
	//t_stack *limits;

	//limits = stack_new(min);
	//stack_add_back(&limits, stack_new(max));
	push_lower_half_to_b(stack_a, stack_b);
	while (*stack_b)
	{
		if (stack_size(*stack_b) > MAX_SIZE_STACK_B)
			push_higher_half_back_to_a(stack_a, stack_b);
		else 
			push_back_to_a_until_sorted(stack_a, stack_b);
	}
	// need to figure out how to make it recursive thanks to limit
	// and how to have the pushed_back_to_a chunks pushed to b until a certain amount (2 by 2 ?)
}

void	push_lower_half_to_b(t_stack **stack_a, t_stack **stack_b) // split
{
	int min;
	int max;
	int	half_value;
	int	size_stack_half;

	min = stack_min_value(*stack_a);
	max = stack_max_value(*stack_a);
	half_value = min + ((max - min) / 2);
	size_stack_half = stack_size(*stack_a) / 2;
	while (size_stack_half)
	{
		if ((*stack_a)->nb < half_value)
		{
			do_action(PUSH_B, stack_a, stack_b);
			size_stack_half--;
		}
		else
			do_action(ROTATE_A, stack_a, stack_b);
	}
}

void	push_higher_half_back_to_a(t_stack **stack_a, t_stack **stack_b) // merge back
{
	int min;
	int max;
	int	half_value;
	int	size_stack_half;

	min = stack_min_value(*stack_b);
	max = stack_max_value(*stack_b);
	half_value = min + ((max - min) / 2);
	size_stack_half = stack_size(*stack_b) / 2;
	while (size_stack_half)
	{
		if ((*stack_b)->nb > half_value)
		{
			do_action(PUSH_A, stack_a, stack_b);
			size_stack_half--;
		}
		else
			do_action(ROTATE_B, stack_a, stack_b);
	}
}

void	push_back_to_a_until_sorted(t_stack **stack_a, t_stack **stack_b) // merge sort
{
	int index;

	index = 0;
	while (*stack_b)
	{
		push_value(MAXIMUM, PUSH_A, stack_a, stack_b);
		do_action(ROTATE_A, stack_a, stack_b);
	}
	while (index < MAX_SIZE_STACK_B) // doesn't work => while *stack a number is != than limit
	{
		do_action(PUSH_B, stack_a, stack_b);
		index++;
	}
	while (*stack_b)
	{
		push_value(MAXIMUM, PUSH_A, stack_a, stack_b);
		do_action(ROTATE_A, stack_a, stack_b);
	}
}


/*
** For 100 random values
** Points : 
** 1500 = 1
** 1300 = 2
** 1100 = 3
** 900 = 4
** 700 = 5
*/

/*
** For 500 random values
** Points : 
** 11500 = 1
** 10000 = 2
** 8500 = 3
** 7000 = 4
** 5500 = 5
*/