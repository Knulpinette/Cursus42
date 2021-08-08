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
# include "../libft/libft.h"
# include "colors.h"

/*
** Structs
*/

typedef struct s_stack
{
	int	nb;
	struct s_stack *next;
}	t_stack;

/*
** Parsing the arguments
*/

//parse_arg(char *argv);

/*
**	Error handling
*/

enum e_error
{
	NOT_NUMBER,
	DUPLICATE,
	OVER_MAX,
	OVER_MIN,
};

#endif