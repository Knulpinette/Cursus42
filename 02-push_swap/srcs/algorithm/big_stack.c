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

// divide in chuncks of 20 => rotate and reverse rotate on stack a and b. 
// understand the recursion concept.
	while (*stack_b)
		push_value(MAXIMUM, PUSH_A, stack_a, stack_b);
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