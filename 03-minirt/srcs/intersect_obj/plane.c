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

void	plane_normal(t_rec *curr, t_ray *cam_ray)
{
	if (dot_product(cam_ray->dir, curr->obj.shape.pl.orient) < 0.0f)
		curr->hit.normal = multiply(normalize(curr->hit.point), -1.0f);
	else
		curr->hit.normal = normalize(curr->hit.point);
}

float	plane(t_ray *ray, t_rec *curr)
{
	t_vec	ray_to_center;
	float	perpendicular;

	perpendicular = dot_product(ray->dir, curr->obj.shape.pl.orient);		
	if (!perpendicular)
		return (0.0);
	ray_to_center = substract(curr->obj.shape.pl.point, ray->ori);
	curr->hit.t = dot_product(ray_to_center, curr->obj.shape.pl.orient)
				/ perpendicular;
	return (curr->hit.t);
}
