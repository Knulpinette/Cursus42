/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:46:22 by osurcouf          #+#    #+#             */
/*   Updated: 2021/08/10 10:46:24 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	push(t_stack **from, t_stack **to)
{
	t_stack *stack_to_push;

	if (!from)
		return (false);
	stack_to_push = stack_new((*from)->nb);
	stack_add_front(to, stack_to_push);
	stack_del_one((*from));
	return (true);
}

void	push_a(t_stack **stack_b, t_stack **stack_a)
{
	if (push(stack_b, stack_a))
		print_action(PUSH_A);	
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	if (push(stack_b, stack_a))
		print_action(PUSH_B);
}
