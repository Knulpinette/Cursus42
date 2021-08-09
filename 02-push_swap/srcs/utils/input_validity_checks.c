/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validity_checks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 13:28:24 by osurcouf          #+#    #+#             */
/*   Updated: 2021/08/09 13:28:25 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	input_is_number(char *argv)
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
