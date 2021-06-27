/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 18:22:37 by osurcouf          #+#    #+#             */
/*   Updated: 2021/04/02 18:22:39 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_res(char *line, t_info *infos)
{
	t_res	*res;

	res = &infos->scene->res;
	line = pass_spaces(line, infos);
	res->x = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line = pass_spaces(line, infos);
	res->y = ft_atoi(line);
	if (res->x < 0 || res->y < 0)
		handle_error("📏	Resolution is negative.\n", infos);
	line = next_nbr(line, infos);
}

void	get_amb(char *line, t_info *infos)
{
	t_ambient	*amb;

	amb = &infos->scene->amb;
	amb->r = ft_atof(line);
	if (amb->r < 0.0 || amb->r > 1.0)
		handle_error("☁️	Ambient ratio should be between 0.0 and 1.0.\n",
						infos);
	line = pass_spaces(line, infos);
	get_color(line, &amb->color, infos);
}

void	get_light(char *line, t_info *infos, int add_mem)
{
	int		current;
	t_scene	*scene;

	scene = infos->scene;
	current = scene->nb_light;
	if (add_mem)
		scene->light = add_mem_light(scene->nb_light, scene->light);
	line = get_vector(line, &scene->light[current].point, infos);
	line = next_nbr(line, infos);
	line = pass_spaces(line, infos);
	scene->light[current].bright = ft_atof(line);
	if (scene->light[current].bright < 0.0
		|| scene->light[current].bright > 1.0)
		handle_error("💡	Light brightness should be between 0.0 and 1.0.\n",
						infos);
	get_color(line, &scene->light[current].color, infos);
}

void	get_cam(char *line, t_info *infos, int add_mem)
{
	int		current;
	t_scene	*scene;

	scene = infos->scene;
	current = scene->nb_cam;
	if (add_mem)
		scene->cam = add_mem_cam(scene->nb_cam, scene->cam);
	line = get_vector(line, &scene->cam[current].point, infos);
	line = next_nbr(line, infos);
	line = get_vector(line, &scene->cam[current].orient, infos);
	scene->cam[current].orient = normalize(scene->cam[current].orient);
	line = next_nbr(line, infos);
	line = pass_spaces(line, infos);
	scene->cam[current].FOV = ft_atof(line);
}
