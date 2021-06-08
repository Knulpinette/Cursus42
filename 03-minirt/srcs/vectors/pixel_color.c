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

static bool	in_shadow(t_rt *rt, int k)
{
	t_vec	light_position;
	t_rec	temp;
	int		i;

	light_position = rt->infos->scene->light[k].point;
	rt->shadow_ray.ori = rt->curr.hit.point;
	rt->shadow_ray.dir = substract(light_position, rt->curr.hit.point);
	rt->curr.t_min = magnitude(rt->shadow_ray.dir);
	rt->curr.t_max = rt->curr.t_min;
	rt->shadow_ray.dir = normalize(rt->shadow_ray.dir);
	i = 0;
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

static float	get_obj_brightness(t_rt *rt, float obj_brightness, int k)
{
	float	light_gain;
	float	light_brightness;
	float	cosine;
	float	degr_to_rad;

	light_brightness = rt->infos->scene->light[k].bright;
	light_gain = dot_product(rt->curr.hit.normal, normalize(rt->light_ray.dir));
	cosine = dot_product(rt->light_ray.dir, rt->light_ray.dir);
	if (light_gain <= 0.0)
		obj_brightness = 0.0;
	else
	{
		degr_to_rad = M_PI * cosine;
		obj_brightness = (light_brightness * light_gain * 1000.0) / degr_to_rad;
		if (in_shadow(rt, k))
			obj_brightness = 0.0;
	}
	return (obj_brightness);
}

static float	get_obj_color(t_rt *rt, float obj_brightness, t_color ambient)
{
	t_color	light_color;
	t_color	add_light_color;
	t_color	add_ambient;
	int		k;

	k = 0;
	while (k < rt->infos->scene->nb_light)
	{
		rt->light_ray.ori = rt->infos->scene->light[k].point;
		rt->light_ray.dir = substract(rt->light_ray.ori, rt->curr.hit.point);
		obj_brightness = get_obj_brightness(rt, obj_brightness, k);
		if (obj_brightness > 1.0)
			obj_brightness = 1.0;
		light_color = rt->infos->scene->light[k].color;
		add_light_color = color_multiply(light_color, obj_brightness);
		rt->curr.obj.color = color_add(rt->curr.obj.color, add_light_color);
		k++;
	}
	add_ambient = color_add(rt->curr.obj.color, ambient);
	rt->curr.pix_color = color_add(rt->curr.pix_color, add_ambient);
	rt->curr.pix_color = convert_to_max(rt->curr.pix_color);
	return (create_color(rt->curr.pix_color));
}

void	get_pixel_color(t_rt *rt)
{
	float	obj_brightness;
	t_color	ambient;

	obj_brightness = 0.0;
	rt->curr.pix_color = rt->curr.obj.color;
	rt->curr.obj.color.r = 0;
	rt->curr.obj.color.g = 0;
	rt->curr.obj.color.b = 0;
	ambient.r = rt->infos->scene->amb.color.r * rt->infos->scene->amb.r;
	ambient.g = rt->infos->scene->amb.color.g * rt->infos->scene->amb.r;
	ambient.b = rt->infos->scene->amb.color.b * rt->infos->scene->amb.r;
	if (rt->curr.hit.t > 0.0 && rt->curr.hit.t != INFINITY)
		rt->curr.pix_color.rgb = get_obj_color(rt, obj_brightness, ambient);
	else
		rt->curr.pix_color.rgb = create_color(ambient);
}

/*
//create the sky
	//t_vec	unit_dir;
	//t_vec	white;
	//t_vec	blue;
	unit_dir = unit_vec(rt->cam_ray.dir);
	t = 0.5 * (unit_dir.y + 1.0);
	white = create_vec(1.0, 1.0, 1.0);
	blue = create_vec(0.5, 0.7, 1.0);
	white = multiply(white, (1.0-t));
	blue = multiply(blue, t);
	return(multiply(add(blue, white), rt->infos->scene->light->bright));*/
