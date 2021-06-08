/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 16:00:52 by osurcouf          #+#    #+#             */
/*   Updated: 2021/04/26 16:00:54 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include "minirt.h"

void	render_minirt(t_rt *rt);
t_vec	create_vec(float a, float b, float c);
t_vec	add(t_vec v1, t_vec v2);
t_vec	substract(t_vec v1, t_vec v2);
t_vec	multiply(t_vec v1, float m);
t_vec	divide(t_vec v1, float d);
float	dot_product(t_vec v1, t_vec v2);
t_vec	cross_product(t_vec v1, t_vec v2);
t_vec	normalize(t_vec v);
float	magnitude(t_vec v);

//pixel_color
void	get_pixel_color(t_rt *rt);
//intersect
float	intersect_obj(t_ray *ray, t_rec *curr);
//sphere
float	intersect_sphere(t_ray *ray, t_rec *curr);
//plane
float	intersect_plane(t_ray *ray, t_rec *curr);
//cylinder
float	intersect_cylinder(t_ray *ray, t_rec *curr);
//quadratic
float	solve_quadratic(t_params param, float *t0, float *t1);
t_params	new_params(float a, float b, float c);

//lookat
t_matrix	look_at(t_vec cam_origin, t_vec cam_dir);
t_vec	multiply_by_matrix(t_vec ray, t_matrix cam);

#endif

