/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:42:00 by osurcouf          #+#    #+#             */
/*   Updated: 2021/03/03 11:43:07 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** 🦕
** function : utils
** 🦕
*/

// DO ERROR HANDLING OF PARSING IN THOSE FUNCTIONS !
// CHECK HOW STRERROR WORKS

char	*next_nbr(char *line)
{
	char	*o_line;

	o_line = line;
	if (*line == '+' || *line == '-')
		line++;
	while (*line && (ft_isdigit(*line) || *line == '.'))
		line++;
	if ((ft_isdigit(*(line + 1)) || *(line + 1) == '+' || *(line + 1) == '-') \
		&& *line == ',')
		line++;
	if (line == o_line)
		handle_error(PARSING_NBR);
	return (line);
}

char	*pass_spaces(char *line)
{
	char	*o_line;

	o_line = line;
	while (*line == ' ' || *line == 9)
		line++;
	if (line == o_line)
		handle_error(PARSING_SPACE);
	return (line);
}