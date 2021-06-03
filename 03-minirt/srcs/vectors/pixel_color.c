/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:22:36 by osurcouf          #+#    #+#             */
/*   Updated: 2021/05/05 14:22:38 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_color	convert_to_max(t_color color)
{
	if (color.r > 255)
		color.r = 255;
	if (color.g > 255)
		color.g = 255;
	if (color.b > 255)
		color.b = 255;
	color.t = 0;
	return (color);
}

bool	check_shadow(t_rt *rt, int k)
{
	int		i;
	t_rec	temp;

	i = 0;

	rt->shadow_ray.ori =  rt->curr.hit.point;
	rt->shadow_ray.dir.x = rt->infos->scene->light[k].point.x - rt->curr.hit.point.x;
	rt->shadow_ray.dir.y = rt->infos->scene->light[k].point.y - rt->curr.hit.point.y;
	rt->shadow_ray.dir.z = rt->infos->scene->light[k].point.z - rt->curr.hit.point.z;
	rt->curr.t_max = vec_magnitude(rt->shadow_ray.dir);
	rt->curr.t_min = rt->curr.t_max;
	rt->shadow_ray.dir = vec_normalize(rt->shadow_ray.dir);
	while (i < rt->infos->nb_objs) 
	{
		temp.obj = rt->infos->objs[i];
		temp.t0 = intersect_obj(&rt->shadow_ray, &temp);
		if (temp.t0 > 0.0001f && temp.t0 < rt->curr.t_min)
				rt->curr.t_min = temp.t0;
		i++;
	}
	if (rt->curr.t_min < rt->curr.t_max)
		return (true);
	return (false);
}

float	get_obj_brightness(t_rt *rt, float obj_bright, int k)
{
	float	l_gain;
	float	magnitude;

	l_gain = vec_dot(rt->curr.hit.normal, vec_normalize(rt->light_ray.dir));

	magnitude = (rt->light_ray.dir.x * rt->light_ray.dir.x) +
			(rt->light_ray.dir.y * rt->light_ray.dir.y) +
			(rt->light_ray.dir.z * rt->light_ray.dir.z);

	if (l_gain <= 0.0)
		obj_bright = 0.0;
	else
	{
		obj_bright = (rt->infos->scene->light[k].bright * l_gain * 1000.0f) / (M_PI * magnitude) + obj_bright;
		if (check_shadow(rt, k))
			obj_bright = 0.0;
	}
	return (obj_bright);
}

void	get_pixel_color(t_rt *rt)
{
	float	obj_bright;
	int		k;

	obj_bright = 0.0;
	k = 0;
	rt->curr.pix_color = rt->curr.obj.color;
	rt->curr.obj.color.r = 0;
	rt->curr.obj.color.g = 0;
	rt->curr.obj.color.b = 0;

	if (rt->curr.hit.t > 0.0 && rt->curr.hit.t != INFINITY)
	{
		while (k < rt->infos->scene->nb_light)
		{
			//printf("LIGHT POINT = %f, %f, %f || LIGHT BRIGHT = %f\n", rt->infos->scene->light[k].point.x, rt->infos->scene->light[k].point.y, rt->infos->scene->light[k].point.z, rt->infos->scene->light[k].bright);
			rt->light_ray.ori = rt->infos->scene->light[k].point;
			rt->light_ray.dir.x = rt->infos->scene->light[k].point.x - rt->curr.hit.point.x;
			rt->light_ray.dir.y = rt->infos->scene->light[k].point.y - rt->curr.hit.point.y;
			rt->light_ray.dir.z = rt->infos->scene->light[k].point.z - rt->curr.hit.point.z;

			obj_bright = get_obj_brightness(rt, obj_bright, k);
			rt->curr.obj.color = color_add(rt->curr.obj.color, color_coeff(rt->infos->scene->light[k].color, obj_bright));
			//printf("light nb = %i || light infos %f \nbrightness = %f || color added lights = %i, %i, %i \n", k, rt->infos->scene->light[k].point.x, obj_bright, rt->curr.obj.color.r, rt->curr.obj.color.g, rt->curr.obj.color.b);
			k++;
		}
		rt->curr.pix_color.r = rt->curr.pix_color.r + (rt->curr.obj.color.r + (rt->infos->scene->amb.color.r * rt->infos->scene->amb.r));
		rt->curr.pix_color.g = rt->curr.pix_color.g + (rt->curr.obj.color.g + (rt->infos->scene->amb.color.g * rt->infos->scene->amb.r));
		rt->curr.pix_color.b = rt->curr.pix_color.b + (rt->curr.obj.color.b + (rt->infos->scene->amb.color.b * rt->infos->scene->amb.r));
		rt->curr.pix_color = convert_to_max(rt->curr.pix_color);
		}
	else
	{
		rt->curr.pix_color.r = rt->infos->scene->amb.color.r * rt->infos->scene->amb.r;
		rt->curr.pix_color.g = rt->infos->scene->amb.color.g * rt->infos->scene->amb.r;
		rt->curr.pix_color.b = rt->infos->scene->amb.color.b * rt->infos->scene->amb.r;
	}
	rt->curr.pix_color.rgb = create_color(rt->curr.pix_color);
}


 // MESS OF CODE


/*static t_color	convert_to_min(t_color color)
{
	if (color.r < 0)
		color.r = 0;
	if (color.g < 0)
		color.g = 0;
	if (color.b < 0)
		color.b = 0;
	color.t = 0;
	return (color);
}
*/



/*
	//t_vec	unit_dir;
	//t_vec	white;
	//t_vec	blue;

//create the sky
	unit_dir = unit_vec(rt->cam_ray.dir);
	t = 0.5 * (unit_dir.y + 1.0);
	white = create_vec(1.0, 1.0, 1.0);
	blue = create_vec(0.5, 0.7, 1.0);
	white = vec_multi(white, (1.0-t));
	blue = vec_multi(blue, t);
	return(vec_multi(vec_add(blue, white), rt->infos->scene->light->bright));*/

