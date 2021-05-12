/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:22:36 by osurcouf          #+#    #+#             */
/*   Updated: 2021/05/05 14:22:38 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	get_obj_color(t_rt *rt, float t)
{
	t_vec	unit_dir;
	t_vec	obj_color;
	t_vec	white;
	t_vec	blue;
	/*float cosine;

	rt->pHit.p = vec_add(rt->ray.ori, vec_multi(rt->ray.dir, t));
	rt->pHit.n = vec_normalize(rt->pHit.p);
	cosine = vec_dot(rt->pHit.n, rt->shadowRay.dir);
	if (cosine < 0)
		cosine = 0;
	obj_color.x = cosine * rt->curr_obj.color.r * rt->infos->scene->light->color.r;
	obj_color.y = cosine * rt->curr_obj.color.g * rt->infos->scene->light->color.g;
	obj_color.z = cosine * rt->curr_obj.color.b * rt->infos->scene->light->color.b;*/

	if (t > 0.0)
	{
		obj_color.x = rt->curr_obj.color.r;
		obj_color.y = rt->curr_obj.color.g;
		obj_color.z = rt->curr_obj.color.b;
		return (vec_multi(obj_color, 0.5));
	}
	//create the sky
	unit_dir = unit_vec(rt->ray.dir);
	t = 0.5 * (unit_dir.y + 1.0);
	white = create_vec(1.0, 1.0, 1.0);
	blue = create_vec(0.5, 0.7, 1.0);
	white = vec_multi(white, (1.0-t));
	blue = vec_multi(blue, t);
	return(vec_add(blue, white));
}

//Light contribution => then mix colors => then get normal depending on which type of shape it is

void	get_pixel_color(t_rt *rt)
{
	t_vec	mix_color;

	mix_color = get_obj_color(rt, rt->pHit.t);
	mix_color = vec_multi(mix_color, rt->infos->scene->light->bright);
	rt->pixel.r = (int)mix_color.x;
	rt->pixel.g = (int)mix_color.y;
	rt->pixel.b = (int)mix_color.z;
	rt->pixel.color = create_rgb(rt->pixel);
}
