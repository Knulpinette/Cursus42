/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 05:45:03 by osurcouf          #+#    #+#             */
/*   Updated: 2021/06/26 05:45:06 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** 🦕
**
** function : Square
**
** blabla
**
** 🦕
*/

float	square(t_ray *ray, t_rec *curr)
{
	t_square	*square;
	float		angle;
	t_vec		origin_to_center;
	t_vec		center_to_hit;

	square = &curr->obj.shape.sq;
	angle = dot_product(square->orient, ray->dir);
	if (!angle)
		return (0.0);
	origin_to_center = substract(square->point, ray->origin);
	curr->hit.t = dot_product(origin_to_center, square->orient) / angle;
	curr->hit.point = add(ray->origin, multiply(ray->dir, curr->hit.t));
	center_to_hit = substract(curr->hit.point, square->point);
	if (curr->hit.t < 0)
		return (0.0);
	else if (fabs(center_to_hit.x) > square->side / 2
		|| fabs(center_to_hit.y) > square->side / 2
		|| fabs(center_to_hit.z) > square->side / 2)
		return (0.0);
	return (curr->hit.t);
}
