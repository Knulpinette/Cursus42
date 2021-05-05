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

void	get_color(char *line, t_color *color)
{
	line = next_nbr(line);
	line = pass_spaces(line);
	color->r = ft_atoi(line);
	line = next_nbr(line);
	color->g = ft_atoi(line);
	line = next_nbr(line);
	color->b = ft_atoi(line);
	if ((color->r < 0 || color->r > 255) \
		|| (color->g < 0 || color->g > 255) \
		|| (color->b < 0 || color->b > 255))
		handle_error(PARSING_COLOR);
	color->color = create_rgb(*color);
}

char	*get_vector(char *line, t_vec *vec)
{
	line = pass_spaces(line);
	vec->x = ft_atof(line);
	line = next_nbr(line);
	vec->y = ft_atof(line);
	line = next_nbr(line);
	vec->z = ft_atof(line);
	return (line);
}
