/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   building_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 13:29:39 by osurcouf          #+#    #+#             */
/*   Updated: 2021/08/09 13:29:40 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	build_stack(t_stack **stack, int nb)
{
	t_stack	*temp;

	if (!*stack)
	{
		*stack = stack_new(nb);
		if (*stack == NULL)
			error(MEMORY_ALLOC, stack, NULL);
	}
	else
	{
		temp = stack_new(nb);
		if (temp == NULL)
			error(MEMORY_ALLOC, stack, NULL);
		stack_add_front(stack, temp);
	}
}
