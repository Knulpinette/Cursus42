/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:20:33 by osurcouf          #+#    #+#             */
/*   Updated: 2021/05/05 14:20:36 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	get_obj_normal(t_rec *curr)
{
	if (curr->obj.type == PLANE)
		curr->hit.normal = normalize(curr->obj.shape.pl.orient);
	if (curr->obj.type == CIRCLE)
		curr->hit.normal = normalize(curr->obj.shape.circle.orient);
	if (curr->obj.type == SPHERE)
		sphere_normal(curr);
	if (curr->obj.type == CYLINDER)
		cylinder_normal(curr);
}

float		intersect_obj(t_ray *ray, t_rec *curr)
{
	t_plane plan;

	if (curr->obj.type == PLANE)
	{
		plan = curr->obj.shape.pl;
		return (plane(ray, curr, plan.point, plan.orient));
	}
	if (curr->obj.type == SPHERE)
		return (sphere(ray, curr));
	if (curr->obj.type == CYLINDER)
		return (cylinder(ray, curr));
	if (curr->obj.type == CIRCLE)
		return (circle(ray, curr));
	return (0);
}

void		check_if_it_hits_object(t_rt *rt)
{
	int		k;
	t_rec	temp;
	float	intersect_point;

	k = 0;
	rt->curr.hit.t = INFINITY;
	while (k < rt->infos->nb_objs)
	{
		temp.obj = rt->infos->objs[k];
		intersect_point = intersect_obj(&rt->cam_ray, &temp);
		if (intersect_point > 0.0 
			&& intersect_point < rt->curr.hit.t)
		{ 
			rt->curr.obj = rt->infos->objs[k];
			rt->curr.hit.t = intersect_point;
		}
		k++;
	}
	if (rt->curr.hit.t != INFINITY)
	{
		rt->curr.hit.point = add(rt->cam_ray.ori, multiply(rt->cam_ray.dir, rt->curr.hit.t));
		get_obj_normal(&rt->curr);
	}
}
