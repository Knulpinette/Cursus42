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
}

void	get_amb(char *line, t_scene *scene)
{
	scene->amb.r = ft_atof(line);
	line = pass_spaces(line);
	line = next_nbr(line);
	line = pass_spaces(line);
	scene->amb.color.r = ft_atoi(line);
	line = next_nbr(line);
	scene->amb.color.g = ft_atoi(line); 
	line = next_nbr(line);
	scene->amb.color.b = ft_atoi(line); 
}

void	get_light(char *line, t_scene *scene, int add_mem)
{
	if (!add_mem)
		scene->light = ft_calloc(sizeof(t_light), 1);
	if (add_mem)
		scene->light = add_mem_light(scene->nb_light, scene->light);
	line = pass_spaces(line);
	scene->light->x = ft_atof(line);
	line = next_nbr(line);
	scene->light->y = ft_atof(line);
	line = next_nbr(line);
	scene->light->z = ft_atof(line);
	line = next_nbr(line);
	line = pass_spaces(line);
	scene->light->bright = ft_atof(line);
	line = next_nbr(line);
	line = pass_spaces(line);
	scene->light->color.r = ft_atoi(line);
	line = next_nbr(line);
	scene->light->color.g = ft_atoi(line); 
	line = next_nbr(line);
	scene->light->color.b = ft_atoi(line); 
}

void	get_cam(char *line, t_scene *scene, int add_mem)
{
	if (!add_mem)
		scene->cam = ft_calloc(sizeof(t_camera), 1);
	if (add_mem)
		scene->cam = add_mem_cam(scene->nb_cam, scene->cam);
	line = pass_spaces(line);
	scene->cam->x = ft_atof(line);
	line = next_nbr(line);
	scene->cam->y = ft_atof(line);
	line = next_nbr(line);
	scene->cam->z = ft_atof(line);
	line = next_nbr(line);
	line = pass_spaces(line);
	scene->cam->vec.x = ft_atof(line);
	line = next_nbr(line);
	scene->cam->vec.y = ft_atof(line);
	line = next_nbr(line);
	scene->cam->vec.z = ft_atof(line);
	line = next_nbr(line);
	scene->cam->hFOV = ft_atoi(line);
	scene->cam->vFOV = (scene->res.x + scene->res.y) - scene->cam->hFOV;
}

/*
printf("AMB   ratio = %f \n \
				rgb = %i, %i, %i\n",\
				scene.amb.r, \
				scene.amb.color.r,\
				scene.amb.color.g,\
				scene.amb.color.b);
printf("  cam x = %i \n\
			cam y = %i \n\
			cam z = %i \n\
			vec.x = %i \n\
			vec.y = %i \n\
			vec.z = %i \n\
			FOV   = %i \n", \
			scene.cam.x, \
			scene.cam.y, \
			scene.cam.z, \
			scene.cam.vec.x, \
			scene.cam.vec.y, \
			scene.cam.vec.z, \
			scene.cam.FOV);

printf("  x = %i \n\
			 y = %i \n\
			 z = %i \n\
			vec.x = %i \n\
			vec.y = %i \n\
			vec.z = %i \n\
			bright = %f \n", \
			scene.light->x, \
			scene.light.y, \
			scene.light.z, \
			scene.light.color.r, \
			scene.light.color.g, \
			scene.light.color.b, \
			scene.light.bright);
*/