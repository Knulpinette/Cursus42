/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:03:10 by osurcouf          #+#    #+#             */
/*   Updated: 2021/04/26 17:03:11 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	vec_add(t_vec v1, t_vec v2)
{
	t_vec	v;

	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	v.z = v1.z + v2.z;
	return (v);
}

t_vec	vec_sub(t_vec v1, t_vec v2)
{
	t_vec	v;

	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	v.z = v1.z - v2.z;
	return (v);
}

t_vec	vec_multi(t_vec v1, float m)
{
	t_vec	v;

	v.x = v1.x * m;
	v.y = v1.y * m;
	v.z = v1.z * m;
	return (v);
}

t_vec	vec_div(t_vec v1, float d)
{
	t_vec	v;

	v.x = v1.x / d;
	v.y = v1.y / d;
	v.z = v1.z / d;
	return (v);
}

float	vec_dot(t_vec v1, t_vec v2)
{
	return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}

float	length_squared(t_vec v)
{
	float x;
	float y;
	float z;

	x = v.x * v.x;
	y = v.y * v.y;
	z = v.z * v.z;
	return (x + y + z);
}

float	length(t_vec v)
{
	float length_sqrd;

	length_sqrd = length_squared(v);
	return (sqrt(length_sqrd));
}