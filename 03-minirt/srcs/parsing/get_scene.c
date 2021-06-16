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

void	get_res(char *line, t_scene *scene)
{
	line = pass_spaces(line);
	scene->res.x = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line = pass_spaces(line);
	scene->res.y = ft_atoi(line);
	if (scene->res.x < 0 || scene->res.y < 0)
		handle_error(PARSING_SCENE);
}

void	get_amb(char *line, t_scene *scene)
{
	scene->amb.r = ft_atof(line);
	if (scene->amb.r < 0.0 || scene->amb.r > 1.0)
		handle_error(PARSING_SCENE);
	line = pass_spaces(line);
	get_color(line, &scene->amb.color);
}

void	get_light(char *line, t_scene *scene, int add_mem)
{
	int	current;

	current = scene->nb_light;
	if (add_mem)
		scene->light = add_mem_light(scene->nb_light, scene->light);
	line = get_vector(line, &scene->light[current].point);
	line = next_nbr(line);
	line = pass_spaces(line);
	scene->light[current].bright = ft_atof(line);
	if (scene->light[current].bright < 0.0 || scene->light[current].bright > 1.0)
		handle_error(PARSING_SCENE);
	get_color(line, &scene->light[current].color);
}

void	get_cam(char *line, t_scene *scene, int add_mem)
{
	int	current;

	current = scene->nb_cam;
	if (add_mem)
		scene->cam = add_mem_cam(scene->nb_cam, scene->cam);
	line = get_vector(line, &scene->cam[current].point);
	line = next_nbr(line);
	line = get_vector(line, &scene->cam[current].orient);
	scene->cam[current].orient = normalize(scene->cam[current].orient);
	line = next_nbr(line);
	line = pass_spaces(line);
	scene->cam[current].FOV = ft_atof(line);
}

/*
printf("AMB   ratio = %f \n \
				rgb = %i, %i, %i\n",\
				scene.amb.r, \
				scene.amb.color.r,\
				scene.amb.color.g,\
				scene.amb.color.b);
printf("  cam x = %f \n\
			cam y = %f \n\
			cam z = %f \n\
			vec.x = %f \n\
			vec.y = %f \n\
			vec.z = %f \n\
			FOV   = %f \n", \
			scene->cam->position.x, \
			scene->cam->position.y, \
			scene->cam->position.z, \
			scene->cam->orient.x, \
			scene->cam->orient.y, \
			scene->cam->orient.z, \
			scene->cam->FOV);

printf("  x = %f \n\
			 y = %f \n\
			 z = %f \n\
			r = %i \n\
			g = %i \n\
			b = %i \n\
			bright = %f \n", \
			scene->light->point.x, \
			scene->light->point.y, \
			scene->light->point.z, \
			scene->light->color.r, \
			scene->light->color.g, \
			scene->light->color.b, \
			scene->light->bright);
*/