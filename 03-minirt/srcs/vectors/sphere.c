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

float	sphere(t_ray *ray, t_rec *curr)
{
	t_sphere	*sp;
	t_vec		center_origin;
	t_params	param;

	sp = &curr->obj.shape.sp;	
	center_origin = substract(ray->ori, sp->point);
	param.a = dot_product(ray->dir, ray->dir);
	param.b = dot_product(center_origin, ray->dir);
	param.c = dot_product(center_origin, center_origin) - (sp->radius * sp->radius);	
	return(solve_quadratic(param, &curr->t0, &curr->t1));
}
