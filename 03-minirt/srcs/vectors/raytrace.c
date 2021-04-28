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

/*
void	intersect_sp(t_obj *obj, t_ray primRay, float *pHit, float *nHit)
{

}


int			get_color(int x, int y, t_rt *rt)
{
	intersect(x, y, rt);
	return(0x00FFFFFF);
}

*/
/*
create_sphere()

dot((p - c),(p - c)) = R*R
=> point - center
*/

t_vec		get_direction(int x, int y, t_rt *rt)
{
	float fov_angle;
	float aspect_ratio;
	float p_x;
	float p_y;
	t_vec unit_vec;

	fov_angle = tan((float)rt->infos->scene->cam->FOV / 2 * M_PI / 180);
	aspect_ratio = (float)rt->infos->scene->res.x / (float)rt->infos->scene->res.y;
	p_x = (2 * (x + 0.5) / (float)rt->infos->scene->res.x - 1) * aspect_ratio * fov_angle;
	p_y = (1 - 2 * (y + 0.5) / (float)rt->infos->scene->res.y) * fov_angle;
	unit_vec.x = p_x;
	unit_vec.y = p_y;
	unit_vec.z = 1;
	return (unit_vec);
}

void	render_minirt(t_rt *rt)
{
	int	x;
	int	y;
	t_scene *scene;

	y = 0;
	scene = rt->infos->scene;
	while (y < scene->res.y)
	{
		x = 0;
		while (x < scene->res.x)
		{
			rt->ray.dir = get_direction(x, y, rt);

			// origin = A
			// dir = B
			//point_at_parameter = A + t*B;
			
			rt->sky_light = create_rgb(scene->amb.color); // pix_color = get_color(x, y, rt);
			my_mlx_pixel_put(&rt->img, x, y, rt->sky_light);
			//printf("x = %f || y = %f || z = %f\n", rt->ray.dir.x, rt->ray.dir.y, rt->ray.dir.z);
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