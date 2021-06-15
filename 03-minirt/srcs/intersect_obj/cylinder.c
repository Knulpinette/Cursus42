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

float	plane2(t_rec *curr, t_vec origin, t_vec orient, float t)
{
	t_vec	ray_to_center;
	float	perpendicular;
	float	angle;
	float	infinity;

	infinity = INFINITY;
	perpendicular = dot_product(orient, curr->obj.shape.pl.orient);		
	if (!perpendicular)
		return (infinity);
	ray_to_center = substract(origin, curr->obj.shape.pl.point);
	angle = dot_product(ray_to_center, curr->obj.shape.pl.orient);
	if ((angle < 0 && perpendicular < 0) || (angle > 0 && perpendicular > 0))
		return (infinity);
	curr->hit.t = -angle
				/ perpendicular;
	if (curr->hit.t < 0 || t < curr->hit.t)
		return (infinity); 
	return (curr->hit.t);
}

void	cylinder_normal(t_rec *curr, t_ray *ray)
{
	t_vec	center_to_hitpoint;
	float	ray_angle;
	t_vec	ray_orient;
	/*t_rec	slice;
	float	t2;
	t_vec	calcul;

	slice.obj.shape.pl.point = curr->obj.shape.cy.point;
	slice.obj.shape.pl.orient = curr->obj.shape.cy.orient;
	t2 = INFINITY;
	t2 = plane2(&slice, ray->ori, curr->obj.shape.cy.orient, t2);
	if (t2 != INFINITY)
	{
		calcul = multiply(curr->obj.shape.cy.orient, t2 * -1);
		calcul = add(curr->obj.shape.cy.point, calcul);
		calcul = substract(ray->ori, calcul);
		calcul = normalize(calcul);
		curr->hit.normal = normalize(calcul);
		return ;
	}
	t2 = plane2(&slice, ray->ori, multiply(curr->obj.shape.cy.orient, -1), t2);
	calcul = multiply(curr->obj.shape.cy.orient, t2);
	calcul = add(curr->obj.shape.cy.point, calcul);
	calcul = substract(ray->ori, calcul);
	curr->hit.normal = normalize(calcul);*/
	center_to_hitpoint = substract(curr->hit.point, curr->obj.shape.cy.point);
	ray_angle = dot_product(curr->obj.shape.cy.orient, center_to_hitpoint);
	ray_orient = multiply(curr->obj.shape.cy.orient, ray_angle);
	curr->hit.normal = normalize(substract(center_to_hitpoint, ray_orient));
	(void)ray;
}

void		check_t_is_in_height(float *hit_point, t_cylinder *cylinder, t_ray *ray)
{
	t_vec orientation;
	t_vec point_to_height;

	point_to_height = add(cylinder->point, multiply(cylinder->orient, cylinder->height));
	orientation = add(ray->ori, multiply(ray->dir, *hit_point));
	if (dot_product(cylinder->orient, substract(orientation, cylinder->point)) < 0.0
		|| dot_product(cylinder->orient, substract(orientation, point_to_height)) > 0.0)
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
	t = plane2(&slice, hit_point, curr->obj.shape.cy.orient, t2);
	if (t <= curr->obj.shape.cy.height / 2)
		return (t);
	else
	{
		t = plane2(&slice, hit_point, multiply(curr->obj.shape.cy.orient, -1), t);
		if (t <= curr->obj.shape.cy.height / 2)
			return (t);
		else
			return (0.0);
	}
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
	