/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:21:49 by osurcouf          #+#    #+#             */
/*   Updated: 2021/05/05 14:21:51 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_params	new_params(float a, float b, float c)
{
	t_params	params;

	params.a = a;
	params.b = b;
	params.c = c;
	return (params);
}

bool	solve_quadratic(t_params param, float *t0, float *t1)
{
	float	discriminant;
	float	temp;

	discriminant = (param.b * param.b) - (param.a * param.c);
	if (discriminant < 0)
		return (false);
	else if (discriminant == 0)
	{
		*t0 = param.b / param.a;
		*t1 = param.b / param.a;
	}
	else
	{
		*t0 = (-param.b - sqrt(discriminant)) / param.a;
		*t1 = (-param.b + sqrt(discriminant)) / param.a;
	}
	if (*t0 > *t1)
	{
		temp = *t0;
		*t0 = *t1;
		*t1 = temp;
	}
	return (true);
}
