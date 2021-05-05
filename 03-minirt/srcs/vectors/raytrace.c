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
	t_vec	lower_left_corner;
	t_vec	horizontal;
	t_vec	vertical;
	float	u;
	float	v;
	t_scene *scene;

	scene = rt->infos->scene;
	nb_objs = rt->infos->nb_objs;

	rt->ray.ori = rt->infos->scene->cam->point;
	y = scene->res.y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < scene->res.x)
		{
			u = ((float)x + 0.5) / (float)scene->res.x;
			v = 1 - (((float)y + 0.5) / (float)scene->res.y);

			//rt->ray.dir = get_direction(x, y, rt);
			vertical = vec_multi(create_vec(0.0, 2.0, 0.0), v);
			horizontal = vec_multi(create_vec(4.0, 0.0, 0.0), u);
			lower_left_corner = create_vec(-2.0, -1.0, -1.0);
			rt->ray.dir = vec_add(vec_add(vertical, horizontal), lower_left_corner);

			//INTERSECT
			k = 0;
			min_distance = INFINITY;
			float distance;
			distance = INFINITY;
			while (k < nb_objs)
			{
				if (intersect_obj(&rt->ray, &rt->infos->objs[k]) > 0.0)
				{
					distance = intersect_sphere(&rt->ray, &rt->infos->objs[k]);
					if (distance < min_distance)
					{
						rt->curr_obj = rt->infos->objs[k];
						min_distance = distance;
					}
				}
				k++;
			}
			/*int isShadow = no;
			pHit = vec_multi(vec_add(rt->ray.ori, rt->ray.dir), distance);
			t_ray shadowRay;
			if (rt->curr_obj.type) 
			{
				shadowRay.dir = vec_sub(scene->light->point, pHit);
				k = 0;
				while (k < nb_objs)
				{
					if (intersect_obj(&shadowRay, &rt->infos->objs[k]) > 0.0)
					{
						isShadow = yes;
						break;
					}
					k++;
				}
			}
			if (!isShadow)
			{ */
				//t = intersect_sphere(&shadowRay, &rt->curr_obj); // this ALSO haha
				rt->pHit.t = intersect_sphere(&rt->ray, &rt->curr_obj);
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