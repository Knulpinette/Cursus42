/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:56:12 by osurcouf          #+#    #+#             */
/*   Updated: 2021/04/26 15:56:14 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


t_vec		get_cam_ray_direction(int x, int y, t_rt *rt)
{
	float fov_angle;
	float aspect_ratio;
	float pixel_ratio_horizontal;
	float pixel_ratio_vertical;

	fov_angle = tan(((float)rt->infos->scene->cam->FOV / 2) * (M_PI / 180));
	aspect_ratio = (float)rt->infos->scene->res.x / (float)rt->infos->scene->res.y;
	pixel_ratio_horizontal = (2 * (x + 0.5) / (float)rt->infos->scene->res.x - 1) * aspect_ratio * fov_angle;
	pixel_ratio_vertical = (1 - 2 * (y + 0.5) / (float)rt->infos->scene->res.y) * fov_angle;
	return (create_vec(pixel_ratio_horizontal, pixel_ratio_vertical, 1));
}

void	render_minirt(t_rt *rt)
{
	int	x;
	int	y;
	int k;
	int	nb_objs;
	//float	magnitude;
	float	min_distance;

	t_scene *scene;


	scene = rt->infos->scene;
	nb_objs = rt->infos->nb_objs;

	rt->cam_ray.ori = rt->infos->scene->cam->point;
	y = 0;
	x = 0;

	while (y < scene->res.y)
	{
		x = 0;
		while (x < scene->res.x)
		{
			t_matrix cam_to_world;
			cam_to_world = look_at(rt->infos->scene->cam->point, rt->infos->scene->cam->orient);
			rt->cam_ray.ori = multiply_by_matrix(create_vec(0, 0, 0), cam_to_world);
			rt->cam_ray.dir = get_cam_ray_direction(x, y, rt);
			rt->cam_ray.dir = multiply_by_matrix(rt->cam_ray.dir, cam_to_world);
			rt->cam_ray.dir = vec_sub(rt->cam_ray.dir, rt->cam_ray.ori);
			rt->cam_ray.dir = vec_normalize(rt->cam_ray.dir); 



//********* INTERSECT OBJECT
			k = 0;
			t_rec temp;
			min_distance = INFINITY;
			rt->curr.hit.t = INFINITY;
			while (k < nb_objs)
			{
				temp.obj = rt->infos->objs[k];
				if (intersect_obj(&rt->cam_ray, &temp) > 0.0 && intersect_obj(&rt->cam_ray, &temp) < min_distance)
				{
					rt->curr.obj = rt->infos->objs[k];
					rt->curr.hit.t = intersect_obj(&rt->cam_ray, &rt->curr);
					min_distance = rt->curr.hit.t;
				}
				k++;
			}

//********* INTERSECTION POINT RECORD => maybe do a t_hit category with curr_obj + infos hit in the class ?

			//rt->curr.hit.point = vec_add(rt->cam_ray.ori, vec_multi(rt->cam_ray.dir, rt->curr.hit.t));
			rt->curr.hit.point.x = rt->cam_ray.ori.x + (rt->cam_ray.dir.x * rt->curr.hit.t);
			rt->curr.hit.point.y = rt->cam_ray.ori.y + (rt->cam_ray.dir.y * rt->curr.hit.t);
			rt->curr.hit.point.z = rt->cam_ray.ori.z + (rt->cam_ray.dir.z * rt->curr.hit.t);

			//compute different normal according to shape of objec
			if (rt->curr.obj.type == SPHERE)
			{
				//rt->curr.hit.normal = vec_normalize(vec_sub(rt->curr.hit.point, rt->curr.obj.shape.sp.point));
				rt->curr.hit.normal.x = (rt->curr.hit.point.x - rt->curr.obj.shape.sp.point.x) / rt->curr.obj.shape.sp.radius;
				rt->curr.hit.normal.y = (rt->curr.hit.point.y - rt->curr.obj.shape.sp.point.y) / rt->curr.obj.shape.sp.radius;
				rt->curr.hit.normal.z = (rt->curr.hit.point.z - rt->curr.obj.shape.sp.point.z) / rt->curr.obj.shape.sp.radius;  
			}
			if (rt->curr.obj.type == PLANE)
			{
				if (vec_dot(rt->cam_ray.dir, rt->curr.obj.shape.pl.orient) < 0.0f)
					rt->curr.hit.normal = vec_multi(vec_normalize(rt->curr.hit.point), -1.0f);
				else
					rt->curr.hit.normal = vec_normalize(rt->curr.hit.point);
			}
			if (rt->curr.obj.type == CYLINDER)
			{
				rt->curr.hit.normal = vec_sub(rt->curr.hit.point, rt->curr.obj.shape.cy.point);
				rt->curr.hit.normal = vec_sub(rt->curr.hit.normal, vec_multi(rt->curr.obj.shape.cy.orient, vec_dot(rt->curr.obj.shape.cy.orient, rt->curr.hit.normal)));
				rt->curr.hit.normal = vec_normalize(rt->curr.hit.normal);
			}


			get_pixel_color(rt);
			my_mlx_pixel_put(&rt->img, x, y, rt->curr.pix_color.rgb);

			x++;
		}
		y++;
	}
}

/*

t_ray		ray_to_pixel(int x, int y, t_scene *scene)
{
	t_v3		origin;
	t_v3		direction;
	t_matrix	c2w;
	t_camera	camera;

	camera = pick_camera(scene);
	c2w = look_at(camera.origin, camera.direction);
	origin = multiply_by_matrix(create_v3(0, 0, 0), c2w);
	direction = get_direction(x, y, scene, camera);
	direction = multiply_by_matrix(direction, c2w);
	direction = substract(direction, origin);
	normalize_vector(&direction);
return (create_ray(origin, direction));

*/