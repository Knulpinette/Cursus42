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
**
** function : parsing utilities
**
**	1. Next_nbr
**		- Moves the cursor from a number to the next while
**			taing into account '-', '+', ','
**	2. Pass_spaces
**		- Passes spaces to naviguate from one block to the
**			other.
**	3. Get_color
**		- Since that particular piece of code was repetitive,
**			I put it aside. Gets the 'r,g,b' block.
**	4. Get_caps
**		- To get a full cylinder (and not just the tube part),
**			I couldn't find another way than to make circles
**			exactly in the right spot for the caps. They are
**			added to the object array, like any other object.
**		Note : if I have the time and motivation, I'll add
**				circles to the list of object you can parse
**				through in the scene.rt file.
**
** 🦕
*/

char	*next_nbr(char *line, t_info *infos)
{
	char	*o_line;

	o_line = line;
	if (*line == '+' || *line == '-')
		line++;
	while (*line && (ft_isdigit(*line) || *line == '.'))
		line++;
	if ((ft_isdigit(*(line + 1)) || *(line + 1) == '+' || *(line + 1) == '-')
		&& *line == ',')
		line++;
	if (line == o_line)
		handle_error("🔢	Character is in the wild. Danger. Can't parse.\n",
					 infos);
	return (line);
	(void)infos;
}

char	*pass_spaces(char *line, t_info *infos)
{
	char	*o_line;

	o_line = line;
	while (*line == ' ' || *line == 9)
		line++;
	if (line == o_line)
		handle_error("⌨️	There's a lonely character attached to a number.\n",
						infos);
	return (line);
}

void	get_color(char *line, t_color *color, t_info *infos)
{
	line = next_nbr(line, infos);
	line = pass_spaces(line, infos);
	color->r = ft_atoi(line);
	line = next_nbr(line, infos);
	color->g = ft_atoi(line);
	line = next_nbr(line, infos);
	color->b = ft_atoi(line);
	if ((color->r < 0 || color->r > 255)
		|| (color->g < 0 || color->g > 255)
		|| (color->b < 0 || color->b > 255))
		handle_error("🎨	Color values should in between 0 and 255.\n", infos);
	color->rgb = create_color(*color);
}

char	*get_vector(char *line, t_vec *vec, t_info *infos)
{
	line = pass_spaces(line, infos);
	vec->x = ft_atof(line);
	line = next_nbr(line, infos);
	vec->y = ft_atof(line);
	line = next_nbr(line, infos);
	vec->z = ft_atof(line);
	return (line);
}

void	get_caps(t_info *infos)
{
	t_cylinder	*cy;
	t_circle	*cap;
	t_color		cy_color;
	int			i;

	cy = &infos->objs[infos->nb_objs].shape.cy;
	cy_color = infos->objs[infos->nb_objs].color;
	i = 0;
	while (i < 2)
	{
		infos->nb_objs += 1;
		infos->objs = add_mem_obj(infos->nb_objs, infos->objs);
		if (!infos->objs)
			handle_error("💧	Fail to malloc circle.\n", infos);
		infos->objs[infos->nb_objs].type = CIRCLE;
		infos->objs[infos->nb_objs].color = cy_color;
		cap = &infos->objs[infos->nb_objs].shape.circle;
		cap->center = add(cy->point, multiply(cy->orient, cy->height / 2));
		cap->radius = cy->radius;
		cap->orient = cy->orient;
		i++;
	}
}
