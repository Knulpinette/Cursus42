/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 14:06:42 by osurcouf          #+#    #+#             */
/*   Updated: 2021/08/04 14:06:44 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "colors.h"

/*  GET RID OFF !!!  */
#include <stdio.h>

/*
** Structs
*/

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}	t_stack;

/*
**	Algorithm
*/

/*
**	Stack actions fonctions
*/

/*
**	Stack lists fonctions
*/

void	build_stack(t_stack **stack, int nb);
void	stack_add_back(t_stack **stack, t_stack *new);
void	stack_add_front(t_stack **stack, t_stack *new);
void	stack_clear(t_stack **stack);
void	stack_del_one(t_stack *stack);
t_stack	*stack_last(t_stack *stack);
t_stack	*stack_new(int nb);
int		stack_size(t_stack *stack);

/*
** Input validity checks
*/

bool	input_is_number(char *argv);
bool	there_is_duplicate(t_stack **stack);
bool	stack_is_sorted(t_stack **stack);

/*
**	Error handling
*/

enum e_error
{
	NOT_NUMBER,
	DUPLICATE,
	OVER_MAX,
	OVER_MIN,
	MEMORY_ALLOC,
	SORTED,
};

int		error(int error, t_stack **stack_a, t_stack **stack_b);
void	error_message(int error);

#endif