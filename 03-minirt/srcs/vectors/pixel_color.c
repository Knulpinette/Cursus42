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

t_color	get_obj_brightness(t_rt *rt, float t)
{
	float	l_gain;
	float	magnitude;
	float	obj_bright;

	l_gain = vec_dot(rt->pHit.n, vec_normalize(rt->light_ray.dir));

	magnitude = (rt->light_ray.dir.x * rt->light_ray.dir.x) +
			(rt->light_ray.dir.y * rt->light_ray.dir.y) +
			(rt->light_ray.dir.z * rt->light_ray.dir.z);

	if (l_gain <= 0.0)
		obj_bright = 0.0;
	else
		obj_bright = (rt->infos->scene->light->bright * l_gain * 1000.0f) / (M_PI * magnitude);

	rt->pixel.r = rt->pixel.r + ((rt->infos->scene->light->color.r * obj_bright) + (rt->infos->scene->amb.color.r * rt->infos->scene->amb.r));
	rt->pixel.g = rt->pixel.g + ((rt->infos->scene->light->color.g * obj_bright) + (rt->infos->scene->amb.color.g * rt->infos->scene->amb.r));
	rt->pixel.b = rt->pixel.b + ((rt->infos->scene->light->color.b * obj_bright) + (rt->infos->scene->amb.color.b * rt->infos->scene->amb.r));
	rt->pixel = convert_to_max(rt->pixel);

	return (rt->pixel);

	(void)t;
}

void	get_pixel_color(t_rt *rt)
{
	rt->pixel = rt->curr_obj.color;

//********* IF INTERSECT_OBJ, GET BRIGHTNESS OF THE CONTACT POINT
	if (rt->distance > 0.0 && rt->distance != INFINITY)
		rt->pixel = get_obj_brightness(rt, rt->distance);
	else
	{
		rt->pixel.r = rt->infos->scene->amb.color.r * rt->infos->scene->amb.r;
		rt->pixel.g = rt->infos->scene->amb.color.g * rt->infos->scene->amb.r;
		rt->pixel.b = rt->infos->scene->amb.color.b * rt->infos->scene->amb.r;
	}
	rt->pixel.color = create_color(rt->pixel);
}


// ******** CODE TO DEBUG ZEBRA ***************
/*printf(">> %.f || l_gain %- .3f >> || length >> %- .1f \
|| light_dir >> %- .3f, %- .3f, %- .3f\n", \
rt->curr_obj.shape.sp.radius, l_gain, length, \
rt->light_ray.dir.x, rt->light_ray.dir.y, \
rt->light_ray.dir.z);

printf("r >> %i g >> %i  b >> %i -> %f\n",
convert_to_zero(color_div(rt->infos->scene->light->color, obj_bright)).r,
convert_to_zero(color_div(rt->infos->scene->light->color, obj_bright)).g,
convert_to_zero(color_div(rt->infos->scene->light->color, obj_bright)).b, obj_bright);
rt->pixel = color_add(rt->pixel, convert_to_zero(color_coeff(rt->infos->scene->light->color, obj_bright))); 



printf(">> %.f || l_gain %- .3f >> || magnitude >> %- .1f \
	|| light_dir >> %- .3f, %- .3f, %- .3f || ", \
	rt->curr_obj.shape.sp.radius, l_gain, magnitude, \
	rt->light_ray.dir.x, rt->light_ray.dir.y, \
	rt->light_ray.dir.z);

printf("brightness = %.3f", obj_bright); */


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

	

/*t_color	get_obj_color(t_rt *rt, float t, int curr_light)
{
	t_color	obj_color;
	float	l_gain;
	float	distance;
	float	obj_bright;

	l_gain = vec_dot(rt->pHit.n, rt->light_ray.dir);
	distance = vec_len(rt->light_ray.dir);
	if (t > 0.0)
	{
		if (l_gain <= 0.0)
			obj_bright = 0.0;
		else
			obj_bright = (rt->infos->scene->light[curr_light].bright * l_gain * 1000.0f) / (M_PI * distance);
		obj_color = color_add(rt->curr_obj.color, color_coeff(rt->infos->scene->light[curr_light].color, obj_bright));
		if (curr_light > 0)
			return (color_add(obj_color, rt->mix_color));
		else
			return (obj_color);
	}
	else
		return(color_coeff(rt->infos->scene->amb.color, rt->infos->scene->amb.r));
}

void	get_pixel_color(t_rt *rt)
{
	int	curr_light;
	int isShadow;
	int k;

	isShadow = no;
	curr_light = 0;
	while (curr_light < rt->infos->scene->nb_light)
	{
		rt->light_ray.ori = rt->infos->scene->light[curr_light].point;
		rt->light_ray.dir = vec_sub(rt->infos->scene->light[curr_light].point, rt->pHit.p);
		rt->light_ray.dir = vec_normalize(rt->light_ray.dir);
		
		rt->shadow_ray.ori = vec_div(rt->light_ray.dir, 10000.0f);
		rt->shadow_ray.dir = rt->light_ray.dir;

		if (rt->curr_obj.type) 
		{
			k = 0;
			while (k < rt->infos->nb_objs)
			{
				if (intersect_obj(&rt->light_ray, &rt->infos->objs[k]) > 0.0)
				{
					isShadow = yes;
					break;
				}
				k++;
			}
		}
		if (!isShadow)
		{
			rt->mix_color = get_obj_color(rt, rt->pHit.t, curr_light);
			rt->pixel.color = (int)create_color(rt->mix_color);
		}
		else
			rt->pixel.color = 12;
	}*/