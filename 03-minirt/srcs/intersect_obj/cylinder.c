/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 22:20:47 by osurcouf          #+#    #+#             */
/*   Updated: 2021/05/27 22:20:49 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cylinder_normal(t_rec *curr)
{
	t_vec	center_to_hitpoint;
	float	hit_angle;
	t_vec	hit_length;
	
	center_to_hitpoint = substract(curr->hit.point, curr->obj.shape.cy.point);
	hit_angle = dot_product(curr->obj.shape.cy.orient, center_to_hitpoint);
	hit_length = multiply(curr->obj.shape.cy.orient, hit_angle);
	curr->hit.normal = normalize(substract(center_to_hitpoint, hit_length));
}

bool	hit_point_is_in_length(float *hit_point, t_cylinder *cylinder, t_ray *ray)
{
	t_vec	cylinder_length;
	t_vec	distance_to_hit_point;
	float	entry_point;
	float	exit_point;

	cylinder_length = add(cylinder->point, 
					multiply(cylinder->orient, cylinder->height));
	distance_to_hit_point = add(ray->ori, multiply(ray->dir, *hit_point));
	entry_point = dot_product(cylinder->orient, substract(distance_to_hit_point, cylinder->point));
	exit_point = dot_product(cylinder->orient, substract(distance_to_hit_point, cylinder_length));
	if (entry_point < 0.0 || exit_point > 0.0)
		return (false);
	return (true);
}

float	get_right_intersection_point(t_ray *ray, t_rec *curr)
{
	if (curr->t0 > 0)
		if (hit_point_is_in_length(&curr->t0, &curr->obj.shape.cy, ray))
			return (curr->t0);
	if (curr->t1 > 0)
		if (hit_point_is_in_length(&curr->t1, &curr->obj.shape.cy, ray))
			return (curr->t1);
	return (0.0);
}

float	cylinder(t_ray *ray, t_rec *curr)
{
	t_params 	param;
	t_vec		radius_in_direction_ray;
	t_vec		radius_in_direction_center;
	t_vec		center_to_ray;
	t_cylinder	*cy;

	//change ray->ori => to ray->origin
	// tout les ori => origin. et orient = orient. Uniformiser.
	//bien vérifier tous les noms, qu'ils soient clairs. 

	cy = &curr->obj.shape.cy;
	//here I'm calculating the radius thats perpendicular to the two vector I'm cross producting
	radius_in_direction_ray = cross_product(ray->dir, cy->orient);
	center_to_ray = substract(ray->ori, cy->point);
	radius_in_direction_center = cross_product(center_to_ray, cy->orient);
	param.a = dot_product(radius_in_direction_ray, radius_in_direction_ray);
	param.b = dot_product(radius_in_direction_ray, radius_in_direction_center);
	param.c = dot_product(radius_in_direction_center, radius_in_direction_center)
			- (cy->radius * cy->radius);
	if (solve_quadratic(param, &curr->t0, &curr->t1))
		return(get_right_intersection_point(ray, curr));
	else
		return (0.0);
	
}
	