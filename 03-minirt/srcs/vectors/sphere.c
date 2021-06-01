/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:21:15 by osurcouf          #+#    #+#             */
/*   Updated: 2021/05/05 14:21:16 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	intersect_sphere(t_ray *ray, t_rec *curr)
{
	t_sphere	*sp;
	t_vec		center_origin;
	float		a;
	float		b;
	float		c;

	sp = &curr->obj.shape.sp;
	
	//center_ori = vec_sub(ray->ori, sp->point);
	center_origin.x = ray->ori.x - sp->point.x;
	center_origin.y = ray->ori.y - sp->point.y;
	center_origin.z = ray->ori.z - sp->point.z;

	//a = vec_dot(ray->dir, ray->dir);
	a = (ray->dir.x * ray->dir.x) +
		(ray->dir.y * ray->dir.y) +
		(ray->dir.z * ray->dir.z);

	//b = vec_dot(center_ori, ray->dir);
	b = (center_origin.x * ray->dir.x) +
		(center_origin.y * ray->dir.y) +
		(center_origin.z * ray->dir.z);

	//c = vec_dot(center_ori, center_ori) - (sp->radius * sp->radius);
	c = ((center_origin.x * center_origin.x) +
		(center_origin.y * center_origin.y) +
		(center_origin.z * center_origin.z)) -
		(sp->radius * sp->radius);
	
	return(solve_quadratic(new_params(a, b, c), &curr->t0, &curr->t1));
}
