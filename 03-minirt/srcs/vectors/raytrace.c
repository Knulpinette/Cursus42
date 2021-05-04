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



float	intersect_sphere(t_ray *ray, t_obj *obj)
{
	t_sphere	*sp;
	t_vec		oc;
	float		a;
	float		b;
	float		c;
	float		discriminant;

	sp = &obj->shape.sp;
	oc = vec_sub(ray->ori, sp->point);
	a = vec_dot(ray->dir, ray->dir);
	b = vec_dot(oc, ray->dir);
	c = vec_dot(oc, oc) - (sp->radius * sp->radius);
	discriminant = (b * b) - (a * c);
	//if (discriminant > 0) //retirer
		//printf("discriminant = %f\n", (-b -sqrt(discriminant) / a)); //retirer
	if (discriminant < 0)
		return (-1.0);
	else
		return ((-b -sqrt(discriminant)) / a);
}

t_vec	obj_color(t_rt *rt, float t)
{
	t_vec	unit_dir;
	t_vec	white;
	t_vec	blue;
	t_vec	N;
	t_vec	point_at_parameter;

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

float	intersect_obj(t_ray *ray, t_obj *obj)
{
	if (obj->type != -1.0)
	{
		if (obj->type == SPHERE)
			return (intersect_sphere(ray, obj));
	}
	return (0);
}

t_vec	intersection_point(t_ray *ray, t_obj *obj)
{
	t_sphere	*sp;
	t_vec		oc;
	float		a;
	float		b;
	float		c;

	sp = &obj->shape.sp;
	oc = vec_sub(ray->ori, sp->point);
	a = vec_dot(ray->dir, ray->dir);
	b = vec_dot(oc, ray->dir);
	c = vec_dot(oc, oc) - (sp->radius * sp->radius);
	//printf("a >>> %f || b >>> %f || c >>> %f\n", a, b, c);
	return(create_vec(a, b, c));
}

void	render_minirt(t_rt *rt)
{
	int	x;
	int	y;
	int k;
	int	nb_objs;
	t_vec	pHit;
	float	min_distance;
	t_vec	lower_left_corner;
	t_vec	horizontal;
	t_vec	vertical;
	t_vec	object_color;
	t_vec	pixel_color;
	t_color pix_color;
	float	u;
	float	v;
	t_scene *scene;
	//float fov_angle;
	//float aspect_ratio;

	scene = rt->infos->scene;
	nb_objs = rt->infos->nb_objs;

	rt->ray.ori = rt->infos->scene->cam->point;
	y = scene->res.y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < scene->res.x)
		{
			//fov_angle = tan((float)scene->cam->FOV / 2 * M_PI / 180);
			//aspect_ratio = 0.5 * ((float)scene->res.x / (float)scene->res.y);
			//u = (((2 * ((float)x + 0.5) / (float)scene->res.x))) * fov_angle * aspect_ratio;
			//v = 1 - ((2 * ((float)y + 0.5) / (float)scene->res.y)) * fov_angle;

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
			while (k < nb_objs)
			{
				if (intersect_obj(&rt->ray, &rt->infos->objs[k]) > 0.0)
				{
					float distance;
					distance = intersect_sphere(&rt->ray, &rt->infos->objs[k]);
					if (distance < min_distance)
					{
						rt->curr_obj = rt->infos->objs[k];
						min_distance = distance;
					}
				}
				k++;
			}
			int isShadow = no;
			pHit = intersection_point(&rt->ray, &rt->curr_obj);
			t_ray shadowRay;
			if (rt->curr_obj.type) // this is not zorking AT ALL haha
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
			{
				float t;
				//t = intersect_sphere(&shadowRay, &rt->curr_obj); // this ALSO haha
				t = intersect_sphere(&rt->ray, &rt->curr_obj);

				object_color = obj_color(rt, t);

				pixel_color = vec_multi(object_color, scene->light->bright);
				pix_color.r = (int)pixel_color.x;
				pix_color.g = (int)pixel_color.y;
				pix_color.b = (int)pixel_color.z;

				rt->sky_light = create_rgb(pix_color); 
				my_mlx_pixel_put(&rt->img, x, y, rt->sky_light);
			}
			else 
				my_mlx_pixel_put(&rt->img, x, y, 0x00FFFFFF);
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