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

//void	intersect_sp(t_obj *obj, t_ray primRay, float *pHit, float *nHit)
//{

//}

void	render_minirt(t_rt *rt)
{
	int	i;
	int	j;
	t_scene *scene;
	//t_vec	ray_vec;

	i = 0;
	j = 0;
	scene = rt->infos->scene;
	while (j < scene->res.y)
	{
		while (i < scene->res.x)
		{
			
			rt->primRay.m = scene->cam->vec.x + i;
			rt->primRay.d = scene->cam->vec.y + j;

			/*printf("cam x = %f || cam y = %f\n \
					pix i = %d || pix j = %d\n \
					primRay m = %f || primRay d = %f\n", \
					scene->cam->x, \
					scene->cam->y, \
					i, j, \
					rt->primRay.m, rt->primRay.d);*/

			i++;
		}
		j++;
	}

}