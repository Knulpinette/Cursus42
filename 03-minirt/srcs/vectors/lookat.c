/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:24:46 by osurcouf          #+#    #+#             */
/*   Updated: 2021/06/07 14:24:50 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	multiply_by_matrix(t_vec ray, t_matrix cam)
{
	t_vec	multi;

	multi.x = ray.x * cam.m[0][0] + ray.y * cam.m[1][0] + ray.z * cam.m[2][0] + cam.m[3][0];
	multi.y = ray.x * cam.m[0][1] + ray.y * cam.m[1][1] + ray.z * cam.m[2][1] + cam.m[3][1];
	multi.z = ray.x * cam.m[0][2] + ray.y * cam.m[1][2] + ray.z * cam.m[2][2] + cam.m[3][2];
	return (multi);
}

t_matrix	look_at(t_vec cam_origin, t_vec cam_dir)
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
