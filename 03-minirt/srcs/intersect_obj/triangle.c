/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 06:41:37 by osurcouf          #+#    #+#             */
/*   Updated: 2021/06/26 06:41:39 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt"

//Figure out CAM ANGLE problem
//Do Antialiasing
//Do charging bar
//Figure out more events and how to write stuff with changing the cam
//Do a text at the beginning to explain how it works
//Do triangles

/*
void	triangle(t_mini_rt *rt, t_element *triangle, t_vec ori, t_vec dir)
{
	t_solve	s;
	t_vec	v1;
	t_vec	v2;
	t_vec	tvec;
	t_vec	pvec;

	v1 = vec_sub(triangle->point2, triangle->point);
	v2 = vec_sub(triangle->point3, triangle->point);
	pvec = vec_cross(dir, v2);
	s.det = vec_dot(v1, pvec);
	if (fabs(s.det) < 0.00001)
		return ;
	s.c = 1 / s.det;
	tvec = vec_sub(ori, triangle->point);
	s.a = vec_dot(tvec, pvec) * s.c;
	if (s.a < 0 || s.a > 1)
		return ;
	tvec = vec_cross(tvec, v1);
	s.b = vec_dot(dir, tvec) * s.c;
	if (s.b < 0 || s.a + s.b > 1)
		return ;
	rt->t = vec_dot(v2, tvec) * s.c;
}


t_v3		get_triangle_normal(t_triangle triangle)
{
	t_v3	a;
	t_v3	b;
	t_v3	n;

	a = substract(triangle.b, triangle.a);
	b = substract(triangle.c, triangle.a);
	n = cross_product(a, b);
	normalize_vector(&n);
	return (n);
}

int			check_edges(t_triangle triangle, t_v3 p, t_v3 n)
{
	t_v3	c;
	t_v3	edge;
	t_v3	vp;

	edge = substract(triangle.b, triangle.a);
	vp = substract(p, triangle.a);
	c = cross_product(edge, vp);
	if (dot_product(n, c) < 0)
		return (0);
	edge = substract(triangle.c, triangle.b);
	vp = substract(p, triangle.b);
	c = cross_product(edge, vp);
	if (dot_product(n, c) < 0)
		return (0);
	edge = substract(triangle.a, triangle.c);
	vp = substract(p, triangle.c);
	c = cross_product(edge, vp);
	if (dot_product(n, c) < 0)
		return (0);
	return (1);
}

int			intersect_triangle(t_ray ray, t_triangle triangle, double *t)
{
	t_v3	a;
	t_v3	b;
	t_v3	n;
	double	angle;
	t_v3	p;

	a = substract(triangle.b, triangle.a);
	b = substract(triangle.c, triangle.a);
	n = cross_product(a, b);
	normalize_vector(&n);
	angle = dot_product(n, ray.direction);
	if (fabs(angle) < 0.0)
		return (0);
	*t = (dot_product(n, substract(triangle.a, ray.origin)) / angle);
	if (*t < 0)
		return (0);
	p = v3_add(ray.origin, v3_multiply(ray.direction, *t));
	return (check_edges(triangle, p, n));
}
*/