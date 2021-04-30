/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 20:01:35 by osurcouf          #+#    #+#             */
/*   Updated: 2021/04/02 20:01:36 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minirt.h"

void	get_infos(char *argv, t_rt *rt);
void	init_objs(t_rt *rt);
void	get_res(char *line, t_scene *scene);
void	get_amb(char *line, t_scene *scene);
void	get_cam(char *line, t_scene *scene, int add_mem);
void	get_light(char *line, t_scene *scene, int add_mem);
void	get_sphere(char *line, t_info *infos, int add_mem);
void	get_square(char *line, t_info *infos, int add_mem);
void	get_plane(char *line, t_info *infos, int add_mem);
void	get_cylinder(char *line, t_info *infos, int add_mem);
void	get_triangle(char *line, t_info *infos, int add_mem);
char	*get_vector(char *line, t_vec *vec);
void	get_color(char *line, t_color *color);

#endif
