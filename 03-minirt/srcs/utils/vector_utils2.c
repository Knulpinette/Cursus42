/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:45:46 by osurcouf          #+#    #+#             */
/*   Updated: 2021/04/26 18:45:48 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	vec_cross(t_vec v1, t_vec v2)
{
	t_vec	v;

	v.x = v1.y * v2.z - v1.z * v2.y;
	v.y = v1.z * v2.x - v1.x * v2.z;
	v.z = v1.x * v2.y - v1.y * v2.x;
	return (v);
}

t_vec	vec_normalize(t_vec v)
{
	t_vec	norm;
	float	len;

	len = sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
	norm.x = v.x / len;
	norm.y = v.y / len;
	norm.z = v.z / len;
	return (norm);
}

float	vec_len(t_vec v)
{
	float	len;

	len = sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
	return (len);
}

float	length_sqrt(t_vec v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

t_vec	unit_vec(t_vec v)
{
	return (vec_div(v, vec_len(v)));
}

t_vec	create_vec(float a, float b, float c)
{
	t_vec v;

	v.x = a;
	v.y = b;
	v.z = c;
	return (v);
}
