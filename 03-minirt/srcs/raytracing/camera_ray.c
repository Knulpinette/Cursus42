/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:24:46 by osurcouf          #+#    #+#             */
/*   Updated: 2021/06/07 14:24:50 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vec	multiply_by_matrix(t_vec ray, t_matrix cam)
{
	t_vec	multi;

	multi.x = ray.x * cam.m[0][0] + ray.y * cam.m[1][0] 
			+ ray.z * cam.m[2][0] + cam.m[3][0];
	multi.y = ray.x * cam.m[0][1] + ray.y * cam.m[1][1] 
			+ ray.z * cam.m[2][1] + cam.m[3][1];
	multi.z = ray.x * cam.m[0][2] + ray.y * cam.m[1][2]
			+ ray.z * cam.m[2][2] + cam.m[3][2];
	return (multi);
}

static t_matrix	look_at(t_vec cam_origin, t_vec cam_dir)
{
	t_matrix	cam_to_world;
	t_vec		random;
	t_vec		forward;
	t_vec		right;
	t_vec		up;

	random = create_vec(0.0, 1.0, 0.0);
	random = normalize(random);
	forward = substract(cam_origin, cam_dir);
	forward = normalize(forward);
	right = cross_product(random, forward);
	right = normalize(right);
	up = cross_product(forward, right);
	up = normalize(up);
	cam_to_world.m[0][0] = right.x;
	cam_to_world.m[0][1] = right.y;
	cam_to_world.m[0][2] = right.z;
	cam_to_world.m[1][0] = up.x;
	cam_to_world.m[1][1] = up.y;
	cam_to_world.m[1][2] = up.z;
	cam_to_world.m[2][0] = cam_dir.x;
	cam_to_world.m[2][1] = cam_dir.y;
	cam_to_world.m[2][2] = cam_dir.z;
	cam_to_world.m[3][0] = cam_origin.x;
	cam_to_world.m[3][1] = cam_origin.y;
	cam_to_world.m[3][2] = cam_origin.z;
	return (cam_to_world);
}

static t_vec	get_direction(int x, int y, t_rt *rt)
{
	float fov_angle;
	float aspect_ratio;
	float x_ratio;
	float y_ratio;
	t_vec res;

	res.x = (float)rt->infos->scene->res.x;
	res.y = (float)rt->infos->scene->res.y;
	fov_angle = tan(((float)rt->infos->scene->cam->FOV / 2) * (M_PI / 180));
	aspect_ratio = res.x / res.y;
	x_ratio = ((x + 0.5) / (res.x / 2) - 1) * aspect_ratio * fov_angle;
	y_ratio = (1 - (y + 0.5) / (res.y / 2)) * fov_angle;
	return (create_vec(x_ratio, y_ratio, 1));
}

void	gen_cam_ray(int x, int y, t_rt *rt)
{
	t_matrix	cam_to_world;
	t_camera	*cam;

	cam = rt->infos->scene->cam;
	cam_to_world = look_at(cam->point, cam->orient);
	rt->cam_ray.ori = cam->point;
	rt->cam_ray.dir = get_direction(x, y, rt);
	rt->cam_ray.dir = multiply_by_matrix(rt->cam_ray.dir, cam_to_world);
	rt->cam_ray.dir = substract(rt->cam_ray.dir, rt->cam_ray.ori);
	rt->cam_ray.dir = normalize(rt->cam_ray.dir); 
}