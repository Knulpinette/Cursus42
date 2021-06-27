/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:22:36 by osurcouf          #+#    #+#             */
/*   Updated: 2021/05/05 14:22:38 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	in_shadow(t_rt *rt, int k)
{
	t_vec	light_position;
	t_rec	temp;
	float	hit_dist;
	int		i;

	light_position = rt->infos->scene->light[k].point;
	rt->shadow_ray.origin = rt->curr.hit.point;
	rt->shadow_ray.dir = substract(light_position, rt->curr.hit.point);
	rt->curr.t_min = magnitude(rt->shadow_ray.dir);
	rt->curr.t_max = rt->curr.t_min;
	rt->shadow_ray.dir = normalize(rt->shadow_ray.dir);
	i = 0;
	while (i < rt->infos->nb_objs)
	{
		temp.obj = rt->infos->objs[i];
		hit_dist = intersect_obj(&rt->shadow_ray, &temp);
		if (hit_dist > 0.0001f && hit_dist < rt->curr.t_min)
			rt->curr.t_min = hit_dist;
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
	float	ray_distance;

	light_brightness = rt->infos->scene->light[k].bright;
	light_gain = dot_product(rt->curr.hit.normal,
			normalize(rt->light_ray.dir));
	cosine = dot_product(rt->light_ray.dir, rt->light_ray.dir);
	if (light_gain <= 0.0)
		obj_brightness = 0.0;
	else
	{
		ray_distance = M_PI * cosine;
		obj_brightness = (light_brightness * light_gain * 1000.0)
			/ ray_distance;
		if (in_shadow(rt, k))
			obj_brightness = 0.0;
	}
	return (obj_brightness);
}

static float	get_obj_color(t_rt *rt, float obj_brightness, t_color ambient)
{
	t_color	light_color;
	t_color	add_brightness;
	t_color	add_previous_light;
	t_color	add_ambient;
	int		k;

	k = 0;
	add_previous_light = set(0, 0, 0);
	while (k < rt->infos->scene->nb_light)
	{
		rt->light_ray.origin = rt->infos->scene->light[k].point;
		rt->light_ray.dir = substract(rt->light_ray.origin, rt->curr.hit.point);
		obj_brightness = get_obj_brightness(rt, obj_brightness, k);
		if (obj_brightness > 1.0)
			obj_brightness = 1.0;
		light_color = rt->infos->scene->light[k].color;
		add_brightness = color_multiply(light_color, obj_brightness);
		add_previous_light = color_add(add_previous_light, add_brightness);
		k++;
	}
	add_ambient = color_add(add_previous_light, ambient);
	rt->curr.obj.color = color_add(rt->curr.obj.color, add_ambient);
	rt->curr.obj.color = convert_to_max(rt->curr.obj.color);
	return (create_color(rt->curr.obj.color));
}

void	get_pixel_color(t_rt *rt)
{
	float	obj_brightness;
	t_color	amb_color;
	t_color	amb_light;

	obj_brightness = 0.0;
	amb_color = rt->infos->scene->amb.color;
	amb_light = color_multiply(amb_color, rt->infos->scene->amb.r);
	if (rt->curr.hit.t > 0.0 && rt->curr.hit.t != INFINITY)
		rt->curr.pix_color = get_obj_color(rt, obj_brightness, amb_light);
	else
		rt->curr.pix_color = create_color(amb_light);
}
