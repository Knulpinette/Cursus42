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

/*
** 🦕
**
** function : Cylinder
**
** blabla
**
** 🦕
*/

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

float	circle(t_ray *ray, t_rec *curr)
{
	float		result;
	t_vec		hit_point;
	t_vec		center_to_hit;
	float		length_center_to_hit;
	t_circle	circle;

	circle = curr->obj.shape.circle;
	result = plane(ray, curr, circle.center, circle.orient);
	if (result >= 0.0)
	{
		hit_point = add(ray->origin, multiply(ray->dir, curr->hit.t));
		center_to_hit = substract(hit_point, curr->obj.shape.circle.center);
		length_center_to_hit = dot_product(center_to_hit, center_to_hit);
		if (length_center_to_hit <= circle.radius * circle.radius)
			return (result);
	}
	return (0.0);
}

bool	hit_point_is_in_length(float *hit_point, t_cylinder *cy, t_ray *ray)
{
	t_vec	cylinder_top;
	t_vec	cylinder_bottom;
	t_vec	distance_to_hit_point;
	t_vec	top_cap;
	t_vec	bottom_cap;

	cylinder_top = add(cy->point,
			multiply(multiply(cy->orient, -1), cy->height / 2));
	cylinder_bottom = add(cy->point,
			multiply(cy->orient, cy->height / 2));
	distance_to_hit_point = add(ray->origin, multiply(ray->dir, *hit_point));
	top_cap = substract(distance_to_hit_point, cylinder_top);
	bottom_cap = substract(distance_to_hit_point, cylinder_bottom);
	if (dot_product(cy->orient, top_cap) < 0.0
		|| dot_product(cy->orient, bottom_cap) > 0.0)
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
	t_params	param;
	t_vec		radius_in_direction_ray;
	t_vec		radius_in_direction_center;
	t_vec		center_to_ray;
	t_cylinder	*cy;

	cy = &curr->obj.shape.cy;
	radius_in_direction_ray = cross_product(ray->dir, cy->orient);
	center_to_ray = substract(ray->origin, cy->point);
	radius_in_direction_center = cross_product(center_to_ray, cy->orient);
	param.a = dot_product(radius_in_direction_ray, radius_in_direction_ray);
	param.b = dot_product(radius_in_direction_ray, radius_in_direction_center);
	param.c = dot_product(radius_in_direction_center,
			radius_in_direction_center) - (cy->radius * cy->radius);
	if (solve_quadratic(param, &curr->t0, &curr->t1))
		return (get_right_intersection_point(ray, curr));
	else
		return (0.0);
}
