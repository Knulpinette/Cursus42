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

int	error(int error)
{
	if (error == NOT_NUMBER)
		ft_putstr_fd("Error\nOne of the arguments is not a number", 1);
	if (error == OVER_MAX)
		ft_putstr_fd("Error\nOne of the argument is over the int max", 1);
	if (error == OVER_MIN)
		ft_putstr_fd("Error\nOne of the arguments is under the int min", 1);
	if (error == MEMORY_ALLOC)
		ft_putstr_fd("Error\nMemory badly allocated !", 1);
	exit(EXIT_FAILURE);
}

bool	check_input(char *argv)
{
	size_t i;

	i = 0;
	while (i < ft_strlen(argv))
	{
		if (argv[i] == '+' || argv[i] == '-')
			i++;
		if (!ft_isdigit(argv[i]))
			error(NOT_NUMBER);
		i++;
	}	
	if (ft_atof(argv) > INT_MAX)
		error(OVER_MAX);
	if (ft_atof(argv) < INT_MIN)
		error(OVER_MIN);
	return (true);
}

/*bool	check_duplicate(char *argv, t_stack *stack_a)
{
	
}
*/
int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	*new_stack;
	int		nb;
	int		i;

	if (argc < 2)
		return (EXIT_SUCCESS);
	if (argc == 2)
		return (check_input(argv[1]));
	stack_a = (t_stack **)malloc(sizeof(t_stack *) * (argc - 1));
	if (!stack_a)
		error(MEMORY_ALLOC);
    i = argc - 1;
    while (i > 0)
    {
		if (check_input(argv[i]))// && check_duplicate(argv[i], &stack_a))
		{
			nb = ft_atoi(argv[i]);
			new_stack = stack_new(&nb);
			if (i == 1)
				*stack_a = new_stack;
			printf("\nNEW_NB \n%i >>> passed the check\n", *new_stack->nb);
			//printf("%p >>> is current\n%i >>> is nb\n%p >>> is next\n", new_stack, *new_stack->nb, new_stack->next);
			stack_add_front(stack_a, new_stack);
			//printf(" ______________ \n\nSTACK_BACK \n%p >>> is current\n%i >>> is nb\n%p >>> is next\n\n", new_stack, *new_stack->nb, new_stack->next);
			i--;
		}
    }
	stack_clear(stack_a);
	return (EXIT_SUCCESS);
}

// Figure out how to do the list thing ! 
