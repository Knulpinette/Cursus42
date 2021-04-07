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
	line = pass_spaces(line);
	infos->scene.res.x = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line = pass_spaces(line);
	infos->scene.res.y = ft_atoi(line);
}

void	get_amb(char *line, t_info *infos)
{
	infos->scene.amb.r = ft_atof(line);
	line = pass_spaces(line);
	line = next_nbr(line);
	infos->scene.amb.color.r = ft_atoi(line);
	line = next_nbr(line);
	infos->scene.amb.color.g = ft_atoi(line); 
	line = next_nbr(line);
	infos->scene.amb.color.b = ft_atoi(line); 
}

void	get_light(char *line, t_info *infos)
{
	line = pass_spaces(line);
	infos->scene.light.x = ft_atof(line);
	line = next_nbr(line);
	infos->scene.light.y = ft_atof(line);
	line = next_nbr(line);
	infos->scene.light.z = ft_atof(line);
	line = next_nbr(line);
	line = pass_spaces(line);
	infos->scene.light.bright = ft_atof(line);
	line = next_nbr(line);
	line = pass_spaces(line);
	infos->scene.light.color.r = ft_atoi(line);
	line = next_nbr(line);
	infos->scene.light.color.g = ft_atoi(line); 
	line = next_nbr(line);
	infos->scene.light.color.b = ft_atoi(line); 
}

void	get_cam(char *line, t_info *infos)
{
	line = pass_spaces(line);
	infos->scene.cam.x = ft_atof(line);
	line = next_nbr(line);
	infos->scene.cam.y = ft_atof(line);
	line = next_nbr(line);
	infos->scene.cam.z = ft_atof(line);
	line = next_nbr(line);
	line = pass_spaces(line);
	infos->scene.cam.vec_x = ft_atof(line);
	line = next_nbr(line);
	infos->scene.cam.vec_y = ft_atof(line);
	line = next_nbr(line);
	infos->scene.cam.vec_z = ft_atof(line);
	line = next_nbr(line);
	infos->scene.cam.FOV = ft_atoi(line);
}

/*
printf("AMB   ratio = %f \n \
				rgb = %i, %i, %i\n",\
				infos->scene.amb.r, \
				infos->scene.amb.color.r,\
				infos->scene.amb.color.g,\
				infos->scene.amb.color.b);
printf("  cam x = %i \n\
			cam y = %i \n\
			cam z = %i \n\
			vec x = %i \n\
			vec y = %i \n\
			vec z = %i \n\
			FOV   = %i \n", \
			infos->scene.cam.x, \
			infos->scene.cam.y, \
			infos->scene.cam.z, \
			infos->scene.cam.vec_x, \
			infos->scene.cam.vec_y, \
			infos->scene.cam.vec_z, \
			infos->scene.cam.FOV);

printf("  x = %i \n\
			 y = %i \n\
			 z = %i \n\
			vec x = %i \n\
			vec y = %i \n\
			vec z = %i \n\
			bright = %f \n", \
			infos->scene.light.x, \
			infos->scene.light.y, \
			infos->scene.light.z, \
			infos->scene.light.color.r, \
			infos->scene.light.color.g, \
			infos->scene.light.color.b, \
			infos->scene.light.bright);
*/