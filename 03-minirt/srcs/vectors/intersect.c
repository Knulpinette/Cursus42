/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:20:33 by osurcouf          #+#    #+#             */
/*   Updated: 2021/05/05 14:20:36 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	intersect_obj(t_ray *ray, t_obj *obj)
{
	if (obj->type == SPHERE)
		return (intersect_sphere(ray, obj));
	if (obj->type == PLANE)
		return (intersect_plane(ray, obj));
	return (0);
}
