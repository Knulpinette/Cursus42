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
	rt->curr.t_max = magnitude(rt->shadow_ray.dir);
	rt->curr.t_min = rt->curr.t_max;
	rt->shadow_ray.dir = normalize(rt->shadow_ray.dir);
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

float	get_obj_brightness(t_rt *rt, float obj_brightness, int k)
{
	float	light_gain;
	float	light_brightness;
	float	cosine;

	light_brightness = rt->infos->scene->light[k].bright;
	light_gain = dot_product(rt->curr.hit.normal, normalize(rt->light_ray.dir));

	cosine = (rt->light_ray.dir.x * rt->light_ray.dir.x) +
			(rt->light_ray.dir.y * rt->light_ray.dir.y) +
			(rt->light_ray.dir.z * rt->light_ray.dir.z);

	if (light_gain <= 0.0)
		obj_brightness = 0.0;
	else
	{
		obj_brightness = (light_brightness * light_gain * 1000.0f) / (M_PI * cosine) ;
		if (check_shadow(rt, k))
			obj_brightness = 0.0;
	}
	return (obj_brightness);
}

void	get_pixel_color(t_rt *rt)
{
	float	obj_brightness;
	t_color	ambient;
	int		k;

	obj_brightness = 0.0;
	k = 0;
	rt->curr.pix_color = rt->curr.obj.color;
	rt->curr.obj.color.r = 0;
	rt->curr.obj.color.g = 0;
	rt->curr.obj.color.b = 0;
	ambient = color_multiply(rt->infos->scene->amb.color, rt->infos->scene->amb.r);
	if (rt->curr.hit.t > 0.0 && rt->curr.hit.t != INFINITY)
	{
		while (k < rt->infos->scene->nb_light)
		{
			rt->light_ray.ori = rt->infos->scene->light[k].point;
			rt->light_ray.dir = substract(rt->infos->scene->light[k].point, rt->curr.hit.point);

			obj_brightness = get_obj_brightness(rt, obj_brightness, k);
			if (obj_brightness > 1.0)
				obj_brightness = 1.0;
			rt->curr.obj.color = color_add(rt->curr.obj.color, color_multiply(rt->infos->scene->light[k].color, obj_brightness));
			k++;
		}
		rt->curr.pix_color.r = rt->curr.pix_color.r + (rt->curr.obj.color.r + (rt->infos->scene->amb.color.r * rt->infos->scene->amb.r));
		rt->curr.pix_color.g = rt->curr.pix_color.g + (rt->curr.obj.color.g + (rt->infos->scene->amb.color.g * rt->infos->scene->amb.r));
		rt->curr.pix_color.b = rt->curr.pix_color.b + (rt->curr.obj.color.b + (rt->infos->scene->amb.color.b * rt->infos->scene->amb.r));
		rt->curr.pix_color = convert_to_max(rt->curr.pix_color);
		}
	else
		rt->curr.pix_color = color_multiply(rt->infos->scene->amb.color, rt->infos->scene->amb.r);
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
	white = multiply(white, (1.0-t));
	blue = multiply(blue, t);
	return(multiply(add(blue, white), rt->infos->scene->light->bright));*/

