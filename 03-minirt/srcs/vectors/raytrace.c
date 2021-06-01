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
	//float	magnitude;
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

//********* GET DIRECTION OF CAMERA RAY [NEED TO SOLVE ASPECT RATIO]

			pixel_ratio_horizontal = ((float)x + 0.5) / (float)scene->res.x;
			pixel_ratio_vertical = 1 - (((float)y + 0.5) / (float)scene->res.y);

			//rt->cam_ray.dir = get_direction(x, y, rt);
			//x_axis = vec_multi(create_vec(4.0, 0.0, 0.0), pixel_ratio_horizontal);
			x_axis.x = 4.0 * pixel_ratio_horizontal; // u
			x_axis.y = 0.0 * pixel_ratio_horizontal;
			x_axis.z = 0.0 * pixel_ratio_horizontal;

			//y_axis = vec_multi(create_vec(0.0, 2.0, 0.0), pixel_ratio_vertical);	
			y_axis.x = 0.0 * pixel_ratio_vertical; // v
			y_axis.y = 2.0 * pixel_ratio_vertical;
			y_axis.z = 0.0 * pixel_ratio_vertical;

			//z_axis = create_vec(-2.0, -1.0, -1.0);
			z_axis.x = -2.0;
			z_axis.y = -1.0;
			z_axis.z = -1.0;

			//rt->cam_ray.dir = vec_add(vec_add(x_axis, y_axis), z_axis);
			rt->cam_ray.dir.x = x_axis.x + y_axis.x + z_axis.x;
			rt->cam_ray.dir.y = x_axis.y + y_axis.y + z_axis.y;
			rt->cam_ray.dir.z = x_axis.z + y_axis.z + z_axis.z;

//********* INTERSECT OBJECT
			k = 0;
			t_rec temp;
			min_distance = INFINITY;
			rt->curr.hit.t = INFINITY;
			while (k < nb_objs)
			{
				temp.obj = rt->infos->objs[k];
				if (intersect_obj(&rt->cam_ray, &temp) > 0.0)
				{
					if (intersect_obj(&rt->cam_ray, &temp) < min_distance)
					{
						rt->curr.obj = rt->infos->objs[k];
						rt->curr.hit.t = intersect_obj(&rt->cam_ray, &rt->curr);
						min_distance = rt->curr.hit.t;
					}
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
			/*if (rt->curr.obj.type == PLANE)
			{
				rt->curr.hit.normal = vec_sub(rt->curr.hit.point, rt->curr.obj.shape.cy.point);
				rt->curr.hit.normal = vec_sub(rt->curr.hit.normal, vec_multi(rt->curr.obj.shape.cy.orient, vec_dot(rt->curr.obj.shape.cy.orient, rt->curr.hit.normal)));
				rt->curr.hit.normal = vec_normalize(rt->curr.hit.normal);
			}*/


//********* COMPUTE LIGHT RAY

			rt->light_ray.ori = rt->infos->scene->light->point;

			//rt->light_ray.dir = vec_sub(rt->infos->scene->light->point, rt->curr.hit.point); // needs to not be normalized !
			rt->light_ray.dir.x = rt->infos->scene->light->point.x - rt->curr.hit.point.x;
			rt->light_ray.dir.y = rt->infos->scene->light->point.y - rt->curr.hit.point.y;
			rt->light_ray.dir.z = rt->infos->scene->light->point.z - rt->curr.hit.point.z;


// FIGURE OUT SHADOW RAY !!
			rt->shadow_ray.ori =  rt->curr.hit.point;
			rt->shadow_ray.dir.x = rt->infos->scene->light->point.x - rt->curr.hit.point.x;
			rt->shadow_ray.dir.y = rt->infos->scene->light->point.y - rt->curr.hit.point.y;
			rt->shadow_ray.dir.z = rt->infos->scene->light->point.z - rt->curr.hit.point.z;
			rt->shadow_ray.dir = vec_normalize(rt->shadow_ray.dir);

			int isShadow;
			isShadow = no;

			if (min_distance != INFINITY) 
			{
				k = 0;
				while (k < nb_objs) //change light ray into shadow ray
				{
					temp.obj = rt->infos->objs[k]; //cf plus haut pour premiere definiton de temp
					if (intersect_obj(&rt->light_ray, &temp) > 0.0)
					{
						isShadow = yes;
						break;
					}
					k++;
				}
			}
			if (!isShadow)
//********* GET COLOR OF PIXEL + PRINT PIXEL
				get_pixel_color(rt);
			else
			{
				rt->curr.pix_color.r = 0;
				rt->curr.pix_color.r = 0;
				rt->curr.pix_color.r = 0;
				rt->curr.pix_color.rgb = create_color(rt->curr.pix_color);
			}
			my_mlx_pixel_put(&rt->img, x, y, rt->curr.pix_color.rgb);

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


			//rt->shadow_ray.ori = vec_div(rt->light_ray.dir, 10000.0f);
			//rt->shadow_ray.dir = rt->light_ray.dir;
			if (rt->curr.obj.type) 
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
			{
*/