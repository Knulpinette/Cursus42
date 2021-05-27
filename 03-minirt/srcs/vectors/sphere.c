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

float	solve_quadratic(float a, float b, float c)
{
	float		discriminant;

	discriminant = (b * b) - (a * c);
	if (discriminant < 0)
		return ((-b + sqrt(discriminant)) / a);
	else
		return ((-b - sqrt(discriminant)) / a);
}

float	intersect_sphere(t_ray *ray, t_obj *obj)
{
	t_sphere	*sp;
	t_vec		center_ori;
	float		a;
	float		b;
	float		c;

	sp = &obj->shape.sp;
	
	//center_ori = vec_sub(ray->ori, sp->point);
	center_ori.x = ray->ori.x - sp->point.x;
	center_ori.y = ray->ori.y - sp->point.y;
	center_ori.z = ray->ori.z - sp->point.z;

	//a = vec_dot(ray->dir, ray->dir);
	a = (ray->dir.x * ray->dir.x) +
		(ray->dir.y * ray->dir.y) +
		(ray->dir.z * ray->dir.z);

	//b = vec_dot(center_ori, ray->dir);
	b = (center_ori.x * ray->dir.x) +
		(center_ori.y * ray->dir.y) +
		(center_ori.z * ray->dir.z);

	//c = vec_dot(center_ori, center_ori) - (sp->radius * sp->radius);
	c = ((center_ori.x * center_ori.x) +
		(center_ori.y * center_ori.y) +
		(center_ori.z * center_ori.z)) -
		(sp->radius * sp->radius);
	
	return(solve_quadratic(a, b, c));
}
