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
	int		i;

	if (argc < 2)
		return (EXIT_SUCCESS);
	if (argc == 2)
		return (input_is_valid(argv[1]));
	stack_a = NULL;
    i = argc - 1;
    while (i > 0)
    {
		if (input_is_valid(argv[i]))
			build_stack(&stack_a, ft_atoi(argv[i]));
		i--;
    }
	if (!check_duplicate(&stack_a))
		error(DUPLICATE, &stack_a, NULL);
	stack_clear(&stack_a);
	return (EXIT_SUCCESS);
}
