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

float	intersect_plane(t_ray *ray, t_rec *curr)
{
	float	d;
	float	t;

	d = (ray->dir.x * curr->obj.shape.pl.orient.x) +
		(ray->dir.y * curr->obj.shape.pl.orient.y) +
		(ray->dir.z * curr->obj.shape.pl.orient.z);
		
	if (!d)
		return (d);

	//t = vec_dot(vec_sub(obj->shape.pl.point, ray->ori), obj->shape.pl.orient) / d;
	t = (((curr->obj.shape.pl.point.x - ray->ori.x) * (curr->obj.shape.pl.orient.x)) +
		((curr->obj.shape.pl.point.y - ray->ori.y) * (curr->obj.shape.pl.orient.y)) +
		((curr->obj.shape.pl.point.z - ray->ori.z) * (curr->obj.shape.pl.orient.z)))
		/ d;
	return (t);
}
