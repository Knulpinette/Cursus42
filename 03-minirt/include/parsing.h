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

int		open_fd(char *argv, t_info *infos);
void	get_res(char *line, t_info *infos);
void	get_amb(char *line, t_info *infos);
void	get_cam(char *line, t_info *infos);
void	get_light(char *line, t_info *infos);
void	get_sphere(char *line, t_info *infos);
void	get_square(char *line, t_info *infos);
void	get_plane(char *line, t_info *infos);
void	get_cylinder(char *line, t_info *infos);
void	get_triangle(char *line, t_info *infos);
void	get_color(char *line, t_info *infos);

#endif
