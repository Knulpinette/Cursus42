/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:48:47 by osurcouf          #+#    #+#             */
/*   Updated: 2021/04/02 19:48:48 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minirt.h"

enum e_errors {
	NOT_CLOSED = 1,
	NOT_READ,
	NOT_OPEN,
	NO_WINDOW,
	PARSING_SCENE,
	PARSING_OBJS,
	PARSING_COLOR,
	PARSING_SPACE,
	PARSING_NBR,
};

void		handle_error(int error);
char		*next_nbr(char *line);
char		*pass_spaces(char *line);
void		del_mem_infos(t_info *infos);
t_obj		*add_mem_obj(int nb_objs, t_obj *objs);
t_light		*add_mem_light(int nb_light, t_light *light);
t_camera	*add_mem_cam(int nb_cam, t_camera *cam);

#endif
