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

static void	get_obj_normal(t_rec *curr, t_ray *cam_ray)
{
//compute different normal according to shape of objec
	if (curr->obj.type == SPHERE)
		curr->hit.normal = divide(substract(curr->hit.point, curr->obj.shape.sp.point), curr->obj.shape.sp.radius);
	if (curr->obj.type == PLANE)
	{
		if (dot_product(cam_ray->dir, curr->obj.shape.pl.orient) < 0.0f)
			curr->hit.normal = multiply(normalize(curr->hit.point), -1.0f);
		else
			curr->hit.normal = normalize(curr->hit.point);
	}
	if (curr->obj.type == CYLINDER)
	{
		curr->hit.normal = substract(curr->hit.point, curr->obj.shape.cy.point);
		curr->hit.normal = substract(curr->hit.normal, multiply(curr->obj.shape.cy.orient, dot_product(curr->obj.shape.cy.orient, curr->hit.normal)));
		curr->hit.normal = normalize(curr->hit.normal);
	}
}

static void	check_if_it_hits_object(t_rt *rt)
{
	int k;
	t_rec temp;

	k = 0;
	rt->curr.t_min = INFINITY;
	rt->curr.hit.t = INFINITY;
	while (k < rt->infos->nb_objs)
	{
		temp.obj = rt->infos->objs[k];
		if (intersect_obj(&rt->cam_ray, &temp) > 0.0 && intersect_obj(&rt->cam_ray, &temp) < rt->curr.t_min)
		{
			rt->curr.obj = rt->infos->objs[k];
			rt->curr.hit.t = intersect_obj(&rt->cam_ray, &rt->curr);
			rt->curr.t_min = rt->curr.hit.t;
		}
		k++;
	}
	rt->curr.hit.point = add(rt->cam_ray.ori, multiply(rt->cam_ray.dir, rt->curr.hit.t));
	get_obj_normal(&rt->curr, &rt->cam_ray);
}

void	render_minirt(t_rt *rt)
{
	int	x;
	int	y;
	t_scene *scene;


	scene = rt->infos->scene;
	y = 0;
	x = 0;
	while (y < scene->res.y)
	{
		x = 0;
		while (x < scene->res.x)
		{
			gen_cam_ray(x, y, rt);
			check_if_it_hits_object(rt);
			get_pixel_color(rt);
			my_mlx_pixel_put(&rt->img, x, y, rt->curr.pix_color.rgb);
			x++;
		}
		y++;
	}
}
