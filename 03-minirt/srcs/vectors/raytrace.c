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

dot((p(t) - c),(p(t) - c)) = R*R
=> point - center

====> any of the point satisfying this in on the sphere


blended shadow value = 1-t*start_value+t*end_value
with 0<t<1 normalized from -1<t<1

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
	p_y = (1 - (2 * (y + 0.5)) / (float)rt->infos->scene->res.y) * fov_angle; //verifier si cette valeur est pour y ou z. forward direction
	unit_vec.x = p_x;
	unit_vec.y = p_y;
	unit_vec.z = 1;
	return (unit_vec);
}

t_vec	create_vec(float a, float b, float c)
{
	t_vec v;

	v.x = a;
	v.y = b;
	v.z = c;
	return (v);
}

t_vec	shade_color(t_ray *ray)
{
	t_vec unit_dir;
	float t;
	t_vec un;
	t_vec deux;

	unit_dir = unit_vec(ray->dir);
	t = 0.5*(unit_dir.y + 1.0);
	printf("t >> %f\n", t);
	un = create_vec(1.0, 1.0, 1.0);
	deux = create_vec(0.5, 0.7, 1.0);
	un = vec_multi(un, 1.0-t);
	deux = vec_multi(deux, t);
	return(vec_add(un, deux));
}

void	render_minirt(t_rt *rt)
{
	int	x;
	int	y;
	t_vec	lower_left_corner;
	t_vec	horizontal;
	t_vec	horizontal2;
	t_vec	vertical;
	t_vec	vertical2;
	t_vec	origin;
	t_vec	shadow_color;
	t_vec	pixel_color;
	t_color pix_color;
	float	u;
	float	v;
	t_scene *scene;

	scene = rt->infos->scene;

	lower_left_corner = create_vec(-2.0, -1.0, -1.0);
	horizontal = create_vec(4.0, 0.0, 0.0);
	vertical = create_vec(0.0, 2.0, 0.0);
	origin = create_vec(0.0, 0.0, 0.0);

	rt->ray.ori = origin;
	// origin = A
	// dir = B
	//point_at_parameter = A + t*B;
	
	y = 0;
	while (y < scene->res.y)
	{
		x = 0;
		while (x < scene->res.x)
		{
			u = (float)x / (float)scene->res.x;
			v = (float)y / (float)scene->res.y;

			//rt->ray.dir = get_direction(u, v, rt);
			vertical2 = vec_multi(vertical, v);
			horizontal2 = vec_multi(horizontal, u);
			rt->ray.dir = vec_add(vec_add(lower_left_corner, vertical2), horizontal2);

			shadow_color = shade_color(&rt->ray);
			//printf("R = %f || G = %f || B = %f\n", shadow_color.x, shadow_color.y, shadow_color.z);
			pixel_color = vec_multi(shadow_color, 255.99);
			pix_color.r = (int)pixel_color.x;
			pix_color.g = (int)pixel_color.y;
			pix_color.b = (int)pixel_color.z;
			rt->sky_light = create_rgb(pix_color); // pix_color = get_color(x, y, rt);
			//printf("pix_color = %i\n\n", rt->sky_light);

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