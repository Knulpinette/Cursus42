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

float	plane(t_ray *ray, t_rec *curr, t_vec point, t_vec orient)
{
	t_vec	ray_to_center;
	float	perpendicular;

	perpendicular = dot_product(ray->dir, orient);
	if (!perpendicular)
		return (0.0);
	ray_to_center = substract(point, ray->origin);
	curr->hit.t = dot_product(ray_to_center, orient)
		/ perpendicular;
	return (curr->hit.t);
}
