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
	float	ray_angle;
	t_vec	ray_orient;

	center_to_hitpoint = substract(curr->hit.point, curr->obj.shape.cy.point);
	ray_angle = dot_product(curr->obj.shape.cy.orient, center_to_hitpoint);
	ray_orient = multiply(curr->obj.shape.cy.orient, ray_angle);
	curr->hit.normal = normalize(substract(center_to_hitpoint, ray_orient));
}

void		check_t_is_in_height(float *hit_point, t_cylinder *cylinder, t_ray *ray)
{
	t_vec orientation;
	t_vec point_to_height;

	point_to_height = add(cylinder->point, multiply(cylinder->orient, cylinder->height));
	orientation = add(ray->ori, multiply(ray->dir, *hit_point));
	if (dot_product(cylinder->orient, substract(orientation, cylinder->point)) < 0.0)
		*hit_point = -1;
	if (dot_product(cylinder->orient, substract(orientation, point_to_height)) > 0.0)
		*hit_point = -1;
}

float	get_right_intersection_point(t_ray *ray, t_rec *curr)
{
	float	t;
	float	t2;
	t_vec	hit_point;
	t_rec	slice;

	t = INFINITY;
	printf("AVANT >>> t0 = %f || t1 = %f\n", curr->t0, curr->t1);
	if (curr->t0 > 0)
		t = curr->t0;
	if (curr->t1 > 0)
		t = curr->t1;
	if (t == INFINITY)
		return (0.0);
	hit_point = add(ray->ori, multiply(ray->dir, t));
	slice.obj.shape.pl.point = curr->obj.shape.cy.point;
	slice.obj.shape.pl.orient = curr->obj.shape.cy.orient;
	t2 = INFINITY;
	t2 = plane(ray, &slice);
	if (t2 <= curr->obj.shape.cy.height / 2)
		t = t2;
	else
	{
		ray->dir = divide(ray->dir, -1);
		t2 = plane(ray, &slice);
		if (t2 <= curr->obj.shape.cy.height / 2)
			t = t2;
		ray->dir = divide(ray->dir, -1);
	}
	return (t);
}

/*float	get_right_intersection_point(t_ray *ray, t_rec *curr)
{
	printf("AVANT >>> t0 = %f || t1 = %f\n", curr->t0, curr->t1);
	if (curr->t0 > 0)
		check_t_is_in_height(&curr->t0, &curr->obj.shape.cy, ray);
	if (curr->t1 > 0)
		check_t_is_in_height(&curr->t1, &curr->obj.shape.cy, ray);
	printf("APRES >>>>> t0 = %f || t1 = %f\n", curr->t0, curr->t1);
	if (curr->t0 < 0 && curr->t1 < 0)
		return (0.0);
	if (curr->t0 > 0 && curr->t1 > 0)
		return (0.0);
	if (curr->t1 < curr->t0)
		if (curr->t1 > 0)
			return (curr->t1);
		else
			return (curr->t0);
	else
	{
		if (curr->t0 > 0)
			return (curr->t0);
		else
			return (curr->t1);
	}
}*/

float	cylinder(t_ray *ray, t_rec *curr)
{
	t_params param;
	t_vec	A;
	t_vec	B;
	t_vec center_to_hit;
	t_cylinder *cy;

	cy = &curr->obj.shape.cy;
	A = cross_product(ray->dir, cy->orient);
	center_to_hit = substract(ray->ori, cy->point);
	B = cross_product(center_to_hit, cy->orient);
	param.a = dot_product(A, A);
	param.b = dot_product(A, B);
	param.c = dot_product(B, B) - ((cy->radius * cy->radius) * dot_product(cy->orient, cy->orient));
	if (solve_quadratic(param, &curr->t0, &curr->t1))
		return(get_right_intersection_point(ray, curr));
	else
		return (0.0);
	
}
	