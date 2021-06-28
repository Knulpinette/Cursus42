/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:45:46 by osurcouf          #+#    #+#             */
/*   Updated: 2021/04/26 18:45:48 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** 🦕
**
** function : Algebra utilities.
**		I'll write what I think I understood. Last time I
**		had maths was 10 years ago though. Don't take it
**		too seriously.
**
**	1. Dot_product
**		usually gets you an angle (vec1, vec2) or a distance (vec1, vec1).
**	2. Cross_product
**		will calculate the angle between two vector and calculate
**		the orientation of the infinite plane in between them
**	3. Magnitude
**		now that I'm doing this, I'm realising it's basically a dot_product
**		of the same element squared. Gives the length of a vector.
**	4. Normalize
**		super important calculation that will take a vector and resize it
**		so that its magnitude is 1, thus making it a unit vector.
**		Note : don't forget to normalize. And don't forget not to normalize.
**				Think of that first when you debug.
**
** 🦕
*/

float	dot_product(t_vec v1, t_vec v2)
{
	return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}

t_vec	cross_product(t_vec v1, t_vec v2)
{
	t_vec	v;

	v.x = v1.y * v2.z - v1.z * v2.y;
	v.y = v1.z * v2.x - v1.x * v2.z;
	v.z = v1.x * v2.y - v1.y * v2.x;
	return (v);
}

float	magnitude(t_vec v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

t_vec	normalize(t_vec v)
{
	t_vec	norm;
	float	len;

	len = sqrt(magnitude(v));
	if (len == 0)
		len = 1;
	norm.x = v.x / len;
	norm.y = v.y / len;
	norm.z = v.z / len;
	return (norm);
}
