/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:56:58 by osurcouf          #+#    #+#             */
/*   Updated: 2021/04/20 15:57:00 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_objs(t_rt *rt)
{
	t_info	*init;

	rt->infos = ft_calloc(sizeof(t_info), 1);
	init = rt->infos;
	init->nb_objs = 0;
	init->scene = ft_calloc(sizeof(t_scene), 1);
	init->scene->nb_cam = 0;
	init->scene->nb_light = 0;
	init->objs = ft_calloc(sizeof(t_obj), 1);
}

t_obj	*add_mem_obj(int nb_objs, t_obj *objs)
{
	t_obj	*temp;

	temp = (t_obj *)ft_calloc(sizeof(t_obj), nb_objs);
	ft_memcpy(temp, objs, (sizeof(t_obj) * nb_objs));
	free(objs);
	objs = (t_obj *)ft_calloc(sizeof(t_obj), nb_objs + 1);
	ft_memcpy(objs, temp, (sizeof(t_obj) * nb_objs));
	free(temp);
	return (objs);
}

void	del_mem_infos(t_info *infos)
{
	free(infos->scene->cam);
	free(infos->scene->light);
	free(infos->scene);
	free(infos->objs);
	free((void *)infos);
}