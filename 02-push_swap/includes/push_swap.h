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

/*  GET RID OF !!!  */
#include <stdio.h>

/* ************************************************************************** */
/*                                  Structs                                   */
/* ************************************************************************** */

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}	t_stack;

/* ************************************************************************** */
/*                                 Algorithm                                  */
/* ************************************************************************** */

/* ************************************************************************** */
/*                         Stack actions functions                            */
/* ************************************************************************** */

/* swap */
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_a_b(t_stack **stack_a, t_stack **stack_b);
/* push*/
void	push_a(t_stack **stack_b, t_stack **stack_a);
void	push_b(t_stack **stack_a, t_stack **stack_b);
/* rotate */
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_a);
void	rotate_a_b(t_stack **stack_a, t_stack **stack_b);
/* reverse rotate */
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	reverse_rotate_a_b(t_stack **stack_a, t_stack **stack_b);

/* ************************************************************************** */
/*                         Stack lists functions                              */
/* ************************************************************************** */

void	stack_add_back(t_stack **stack, t_stack *new);
void	stack_add_front(t_stack **stack, t_stack *new);
void	stack_clear(t_stack **stack);
void	stack_del_one(t_stack *stack);
t_stack	*stack_last(t_stack *stack);
t_stack	*stack_new(int nb);
int		stack_size(t_stack *stack);
void	print_stack(t_stack **stack);
void	free_the_stacks(t_stack **stack_a, t_stack **stack_b);

/* ************************************************************************** */
/*                                Utilities                                   */
/* ************************************************************************** */

/* Print actions */

typedef enum e_actions
{
	SWAP_A = 1,
	SWAP_B,
	SWAP_A_B,
	PUSH_A,
	PUSH_B,
	ROTATE_A,
	ROTATE_B,
	ROTATE_A_B,
	REVERSE_ROTATE_A,
	REVERSE_ROTATE_B,
	REVERSE_ROTATE_A_B,
}	t_actions;

void	print_action(t_actions action);

/* Building the stacks */

void	initialize_stack_a(int argc, char **argv, t_stack **stack_a);
void	build_stack(t_stack **stack, int nb);

/* Input validity checks */

bool	input_is_number(char *argv);
bool	there_is_duplicate(t_stack **stack);
bool	stack_is_sorted(t_stack **stack);

/* Error handling */

typedef enum e_error
{
	NOT_NUMBER,
	DUPLICATE,
	OVER_MAX,
	OVER_MIN,
	MEMORY_ALLOC,
	SORTED,
}	t_error;

int		error(t_error error, t_stack **stack_a, t_stack **stack_b);
void	error_message(t_error error);

#endif