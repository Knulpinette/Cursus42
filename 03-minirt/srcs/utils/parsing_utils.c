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

char	*next_nbr(char *line, t_info *infos)
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
		handle_error("parsing nbr", infos);
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
		handle_error("parsing spaces", infos);
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
	if ((color->r < 0 || color->r > 255) \
		|| (color->g < 0 || color->g > 255) \
		|| (color->b < 0 || color->b > 255))
		handle_error("parsing color", infos);
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
	t_circle	*top_cap;
	t_circle	*bottom_cap;
	t_color		cy_color;

	cy = &infos->objs[infos->nb_objs].shape.cy;
	cy_color = infos->objs[infos->nb_objs].color;
	infos->nb_objs += 1;
	infos->objs = add_mem_obj(infos->nb_objs, infos->objs);
	infos->objs[infos->nb_objs].type = CIRCLE;
	infos->objs[infos->nb_objs].color = cy_color;
	top_cap = &infos->objs[infos->nb_objs].shape.circle;
	top_cap->center = add(cy->point, multiply(cy->orient, cy->height / 2));
	top_cap->radius = cy->radius;
	top_cap->orient = cy->orient;
	infos->nb_objs += 1;
	infos->objs = add_mem_obj(infos->nb_objs, infos->objs);
	infos->objs[infos->nb_objs].type = CIRCLE;
	infos->objs[infos->nb_objs].color = cy_color;
	bottom_cap = &infos->objs[infos->nb_objs].shape.circle;
	bottom_cap->center = add(cy->point, multiply(cy->orient, -cy->height / 2));
	bottom_cap->radius = cy->radius;
	bottom_cap->orient = cy->orient;
}
