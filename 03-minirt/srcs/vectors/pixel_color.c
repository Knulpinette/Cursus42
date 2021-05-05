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
	t_vec	white;
	t_vec	blue;

	if (t > 0.0)
	{
		rt->pHit.p = vec_add(rt->ray.ori, vec_multi(rt->ray.dir, t));
		rt->pHit.n = unit_vec(vec_sub(rt->pHit.p, create_vec(0, 0, -1)));
		return (vec_multi(create_vec(rt->pHit.n.x + 1, rt->pHit.n.y + 1, rt->pHit.n.z + 1), 0.5));
	}
	unit_dir = unit_vec(rt->ray.dir);
	t = 0.5 * (unit_dir.y + 1.0);
	white = create_vec(1.0, 1.0, 1.0);
	blue = create_vec(0.5, 0.7, 1.0);
	white = vec_multi(white, (1.0-t));
	blue = vec_multi(blue, t);
	return(vec_add(blue, white));
}

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
