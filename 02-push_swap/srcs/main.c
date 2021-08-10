/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 13:59:51 by osurcouf          #+#    #+#             */
/*   Updated: 2021/08/04 13:59:52 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	if (argc < 2)
		return (EXIT_SUCCESS);
	if (argc == 2)
		return (input_is_number(argv[1]));
	stack_a = NULL;
	stack_b = NULL;
	i = argc - 1;
    while (i > 0)
    {
		if (input_is_number(argv[i]))
			build_stack(&stack_a, ft_atoi(argv[i]));
		i--;
    }
	if (there_is_duplicate(&stack_a))
		error(DUPLICATE, &stack_a, &stack_b);
	if (stack_is_sorted(&stack_a))
		error(SORTED, &stack_a, &stack_b);
	free_the_stacks(&stack_a, &stack_b);
	return (EXIT_SUCCESS);
}
