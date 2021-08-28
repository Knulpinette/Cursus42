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

void	sort_big_stack(int argc, t_stack **stack_a, t_stack **stack_b)
{
	merge_sort(stack_a, stack_b);
	(void)argc;
}

void	merge_sort(t_stack **stack_a, t_stack **stack_b)
{
	/* push half */
	int	half;
	int	index;

	half = stack_size(*stack_a) / 2;
	index = 0;
	while (index < half)
	{
		do_action(PUSH_B, stack_a, stack_b);
		index++;
	}
	while (*stack_b)
		push_value(MAXIMUM, PUSH_A, stack_a, stack_b);

	// divide in chuncks of 20 => rotate and reverse rotate on stack a and b. 
	// => I need to keep track of my chunks.
	// understand the recursion concept. Especially recursion in recursion. Do drawings.
	// but so basically, I send the half of my numbers to the stack_b (median value of my max and min)
	// 
}




// (I need to presort the numbers into stack B // do it with insertion sort ? makes sense if ordering small chunks)
// I NEED TO HAVE THE MEDIAN (sort the whole thing in another double stack ?) OR THE MIDDLE ?




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