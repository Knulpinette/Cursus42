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

void	sphere_normal(t_rec *curr)
{
	t_vec	hit_to_center;
	
	hit_to_center = substract(curr->hit.point, curr->obj.shape.sp.point);
	curr->hit.normal = divide(hit_to_center, curr->obj.shape.sp.radius);
}

float	sphere(t_ray *ray, t_rec *curr)
{
	t_sphere	*sp;
	t_vec		center_origin;
	t_params	param;

	sp = &curr->obj.shape.sp;	
	center_origin = substract(ray->ori, sp->point);
	param.a = dot_product(ray->dir, ray->dir);
	param.b = dot_product(center_origin, ray->dir);
	param.c = dot_product(center_origin, center_origin) - pow(sp->radius, 2);	
	return(solve_quadratic(param, &curr->t0, &curr->t1));
}
