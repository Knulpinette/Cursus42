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

float	intersect_sphere(t_ray *ray, t_obj *obj)
{
	t_sphere	*sp;
	t_vec		oc;
	float		a;
	float		b;
	float		c;
	//float		temp;
	float		discriminant;

	sp = &obj->shape.sp;
	oc = vec_sub(ray->ori, sp->point);
	a = vec_dot(ray->dir, ray->dir);
	b = vec_dot(oc, ray->dir);
	c = vec_dot(oc, oc) - (sp->radius * sp->radius);
	discriminant = (b * b) - (a * c);
	//if (discriminant > 0) //retirer
		//printf("discriminant = %f\n", (-b -sqrt(discriminant) / a)); //retirer
	if (discriminant < 0)
		return (-1.0);
	else
		return ((-b -sqrt(discriminant)) / a);
}
