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
	int min;
	int max;
	t_stack *limits;

	min = stack_min_value(*stack_a);
	max = stack_max_value(*stack_a);
	limits = stack_new(min);
	stack_add_back(&limits, stack_new(max));
	push_lower_half_to_b(stack_a, stack_b, &limits);
	while (*stack_b)
	{
		if (stack_size(*stack_b) > MAX_SIZE_STACK_B)
			push_higher_half_back_to_a(stack_a, stack_b, &limits);
		else 
			push_back_to_a_until_sorted(stack_a, stack_b, &limits);
	}
	stack_clear(&limits);
	// need to figure out how to make it recursive thanks to limit
	// and how to have the pushed_back_to_a chunks pushed to b until a certain amount (2 by 2 ?)
}

void	push_lower_half_to_b(
	t_stack **stack_a, t_stack **stack_b, t_stack **limits) // split
{
	int	size_stack_half;

	get_new_limit(stack_a, limits);
	size_stack_half = stack_size(*stack_a) / 2;
	while (size_stack_half)
	{
		if ((*stack_a)->nb < (*limits)->nb)
		{
			do_action(PUSH_B, stack_a, stack_b);
			size_stack_half--;
		}
		else
			do_action(ROTATE_A, stack_a, stack_b);
	}
}

void	push_higher_half_back_to_a(
	t_stack **stack_a, t_stack **stack_b, t_stack **limits) // merge back
{
	int	size_stack_half;

	get_new_limit(stack_b, limits);
	size_stack_half = stack_size(*stack_b) / 2;
	while (size_stack_half)
	{
		if ((*stack_b)->nb > (*limits)->nb)
		{
			do_action(PUSH_A, stack_a, stack_b);
			size_stack_half--;
		}
		else
			do_action(ROTATE_B, stack_a, stack_b);
	}
}

void	push_back_to_a_until_sorted(
	t_stack **stack_a, t_stack **stack_b, t_stack **limits) // merge sort
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
	(void)limits;
}

void	get_new_limit(t_stack **stack, t_stack **limits)
{
	int min;
	int max;
	int	half_value;

	min = stack_min_value(*stack);
	max = stack_max_value(*stack);
	half_value = min + ((max - min) / 2);
	stack_add_front(limits, stack_new(half_value));
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