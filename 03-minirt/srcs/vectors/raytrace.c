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



float	intersect_sphere(t_rt *rt)
{
	t_sphere 	*sp;
	t_vec		oc;
	float		a;
	float		b;
	float		c;
	float		discriminant;

	sp = &rt->infos->objs->shape.sp;
	oc = vec_sub(rt->ray.ori, sp->point);
	a = vec_dot(rt->ray.dir, rt->ray.dir);
	b = vec_dot(oc, rt->ray.dir);
	c = vec_dot(oc, oc) - (sp->radius * sp->radius);
	discriminant = (b * b) - (a * c);
	if (discriminant < 0)
		return (-1.0);
	else
		return ((-b -sqrt(discriminant)) / a);
}

t_vec	shade_color(t_rt *rt)
{
	t_vec	unit_dir;
	float	t;
	t_vec	white;
	t_vec	blue;
	t_vec	N;
	t_vec	point_at_parameter;

	t = intersect_sphere(rt);
	if (t > 0.0)
	{
		point_at_parameter = vec_add(rt->ray.ori, vec_multi(rt->ray.dir, t));
		N = unit_vec(vec_sub(point_at_parameter, create_vec(0, 0, -1)));
		return (vec_multi(create_vec(N.x + 1, N.y + 1, N.z + 1), 0.5));
	}
	unit_dir = unit_vec(rt->ray.dir);
	t = 0.5 * (unit_dir.y + 1.0);
	white = create_vec(1.0, 1.0, 1.0);
	blue = create_vec(0.5, 0.7, 1.0);
	white = vec_multi(white, (1.0-t));
	blue = vec_multi(blue, t);
	return(vec_add(blue, white));
}

void	render_minirt(t_rt *rt)
{
	int	x;
	int	y;
	t_vec	lower_left_corner;
	t_vec	horizontal;
	t_vec	vertical;
	t_vec	shadow_color;
	t_vec	pixel_color;
	t_color pix_color;
	float	u;
	float	v;
	t_scene *scene;
	//float	fov_angle;
	//float	aspect_ratio;

	scene = rt->infos->scene;

	rt->ray.ori = rt->infos->scene->cam->point;
	y = scene->res.y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < scene->res.x)
		{
			//fov_angle = tan((float)rt->infos->scene->cam->FOV / 2 * M_PI / 180);
			//aspect_ratio = (float)rt->infos->scene->res.x / (float)rt->infos->scene->res.y;
			u = (2 * (x + 0.5) / (float)scene->res.x) - 1;
			v = 1 - (2 * (y + 0.5) / (float)scene->res.y);

			//rt->ray.dir = get_direction(x, y, rt);
			vertical = vec_multi(create_vec(0.0, 2.0, 0.0), v);
			horizontal = vec_multi(create_vec(4.0, 0.0, 0.0), u);
			lower_left_corner = create_vec(-2.0, -1.0, -1.0);
			rt->ray.dir = vec_add(vec_add(vertical, horizontal), lower_left_corner);

			shadow_color = shade_color(rt);
			//printf("R = %f || G = %f || B = %f\n", shadow_color.x, shadow_color.y, shadow_color.z);
			pixel_color = vec_multi(shadow_color, 255.99);
			pix_color.r = (int)pixel_color.x;
			pix_color.g = (int)pixel_color.y;
			pix_color.b = (int)pixel_color.z;
			rt->sky_light = create_rgb(pix_color); 

			my_mlx_pixel_put(&rt->img, x, y, rt->sky_light);
			//printf("x = %f || y = %f || z = %f\n", rt->ray.dir.x, rt->ray.dir.y, rt->ray.dir.z);
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