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

//pixel_color
void	get_pixel_color(t_rt *rt);
//intersect
float	intersect_obj(t_ray *ray, t_rec *curr);
float	sphere(t_ray *ray, t_rec *curr);
float	plane(t_ray *ray, t_rec *curr);
float	cylinder(t_ray *ray, t_rec *curr);
//quadratic
float	solve_quadratic(t_params param, float *t0, float *t1);
t_params	new_params(float a, float b, float c);
//normals
void	plane_normal(t_rec *curr, t_ray *cam_ray);

/*
**	Generate the camera ray
*/

void	gen_cam_ray(int x, int y, t_rt *rt);

#endif

