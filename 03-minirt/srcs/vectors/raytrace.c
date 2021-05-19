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


/*t_vec		get_direction(int x, int y, t_rt *rt)
{
	float fov_angle;
	float aspect_ratio;
	float p_x;
	float p_y;

	fov_angle = tan((float)rt->infos->scene->cam->FOV / 2 * M_PI / 180);
	aspect_ratio = (float)rt->infos->scene->res.x / (float)rt->infos->scene->res.y;
	p_x = (2 * (x + 0.5) / (float)rt->infos->scene->res.x - 1) * aspect_ratio * fov_angle;
	p_y = (1 - (2 * (y + 0.5)) / (float)rt->infos->scene->res.y) * fov_angle; //verifier si cette valeur est pour y ou z. forward direction
	return (create_vec(p_x, p_y, 1));
}*/

void	render_minirt(t_rt *rt)
{
	int	x;
	int	y;
	int k;
	int	nb_objs;
	float	min_distance;
	t_vec	z_axis;
	t_vec	x_axis;
	t_vec	y_axis;
	float	pixel_ratio_horizontal;
	float	pixel_ratio_vertical;
	t_scene *scene;

	scene = rt->infos->scene;
	nb_objs = rt->infos->nb_objs;

	rt->cam_ray.ori = rt->infos->scene->cam->point;
	y = scene->res.y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < scene->res.x)
		{
			pixel_ratio_horizontal = ((float)x + 0.5) / (float)scene->res.x;
			pixel_ratio_vertical = 1 - (((float)y + 0.5) / (float)scene->res.y);

			//rt->cam_ray.dir = get_direction(x, y, rt);
			x_axis = vec_multi(create_vec(4.0, 0.0, 0.0), pixel_ratio_horizontal);
			y_axis = vec_multi(create_vec(0.0, 2.0, 0.0), pixel_ratio_vertical);
			z_axis = create_vec(-2.0, -1.0, -1.0);
			rt->cam_ray.dir = vec_add(vec_add(x_axis, y_axis), z_axis);

			//INTERSECT
			k = 0;
			min_distance = INFINITY;
			rt->distance = INFINITY;
			while (k < nb_objs)
			{
				if (intersect_obj(&rt->cam_ray, &rt->infos->objs[k]) > 0.0)
				{
					rt->distance = intersect_obj(&rt->cam_ray, &rt->infos->objs[k]);
					if (rt->distance < min_distance)
					{
						rt->curr_obj = rt->infos->objs[k];
						min_distance = rt->distance;
					}
				}
				k++;
			}
			//int isShadow = no;
			rt->pHit.p = vec_add(rt->cam_ray.ori, vec_multi(rt->cam_ray.dir, rt->distance));
			rt->pHit.n = vec_normalize(rt->pHit.p);

			rt->light_ray.ori = rt->infos->scene->light->point;
			rt->light_ray.dir = vec_sub(rt->infos->scene->light->point, rt->pHit.p);
			rt->distance = sqrt(vec_dot(rt->light_ray.dir, rt->light_ray.dir));
			rt->light_ray.dir = vec_div(rt->light_ray.dir, rt->distance);

			rt->shadow_ray.ori = vec_div(rt->light_ray.dir, 10000.0f);
			rt->shadow_ray.dir = rt->light_ray.dir;
			/*if (rt->curr_obj.type) 
			{
				k = 0;
				while (k < nb_objs)
				{
					if (intersect_obj(&rt->shadow_ray, &rt->infos->objs[k]) > 0.0)
					{
						isShadow = yes;
						break;
					}
					k++;
				}
			}
			if (!isShadow)
			{*/
				//rt->pHit.t = intersect_obj(&rt->shadow_ray, &rt->curr_obj); // this ALSO haha */
				rt->pHit.t = intersect_obj(&rt->cam_ray, &rt->curr_obj); 
				//calculate brightness and bam
				get_pixel_color(rt);
				my_mlx_pixel_put(&rt->img, x, y, rt->pixel.color);
			/*}
			else 
				my_mlx_pixel_put(&rt->img, x, y, 0x00000000);*/
			x++;
		}
		y--;
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