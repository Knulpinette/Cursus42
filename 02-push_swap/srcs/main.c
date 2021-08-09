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

int	error(int error, t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a)
		stack_clear(stack_a);
	if (stack_b)
		stack_clear(stack_b);
	if (error == NOT_NUMBER)
		ft_putstr_fd("Error\nOne of the arguments is not a number", 1);
	if (error == OVER_MAX)
		ft_putstr_fd("Error\nOne of the argument is over the int max", 1);
	if (error == OVER_MIN)
		ft_putstr_fd("Error\nOne of the arguments is under the int min", 1);
	if (error == MEMORY_ALLOC)
		ft_putstr_fd("Error\nMemory badly allocated !", 1);
	if (error == DUPLICATE)
		ft_putstr_fd("Error\nThere's a duplicate number in your input.", 1);
	exit(EXIT_FAILURE);
}

bool	input_is_valid(char *argv)
{
	size_t i;

	i = 0;
	while (i < ft_strlen(argv))
	{
		if (argv[i] == '+' || argv[i] == '-')
			i++;
		if (!ft_isdigit(argv[i]))
			error(NOT_NUMBER, NULL, NULL);
		i++;
	}	
	if (ft_atof(argv) > INT_MAX)
		error(OVER_MAX, NULL, NULL);
	if (ft_atof(argv) < INT_MIN)
		error(OVER_MIN, NULL, NULL);
	return (true);
}

bool	check_duplicate(t_stack **stack)
{
	t_stack *comparing;
	t_stack *compared;

	comparing = *stack;
	while (comparing)
	{
		compared = comparing->next;
		while (compared)
		{
			if (comparing->nb == compared->nb)
				return (false);
			compared = compared->next;
		}
		comparing = comparing->next;
	}
	return (true);
}

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
