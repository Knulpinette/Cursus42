/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 00:58:46 by osurcouf          #+#    #+#             */
/*   Updated: 2021/05/30 00:58:49 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	intersect_plane(t_ray *ray, t_obj *obj)
{
	float	d;
	float	t;

	d = (ray->dir.x * obj->shape.pl.orient.x) +
		(ray->dir.y * obj->shape.pl.orient.y) +
		(ray->dir.z * obj->shape.pl.orient.z);
		
	if (!d)
		return (d);

	//t = vec_dot(vec_sub(obj->shape.pl.point, ray->ori), obj->shape.pl.orient) / d;
	t = (((obj->shape.pl.point.x - ray->ori.x) * (obj->shape.pl.orient.x)) +
		((obj->shape.pl.point.y - ray->ori.y) * (obj->shape.pl.orient.y)) +
		((obj->shape.pl.point.z - ray->ori.z) * (obj->shape.pl.orient.z)))
		/ d;
	return (t);
}
