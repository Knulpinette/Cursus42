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

float	solve_quadratic(t_params param, float *t0, float *t1)
{
	float		discriminant;

	discriminant = (param.b * param.b) - (param.a * param.c);
	if (discriminant < 0)
		return ((-param.b + sqrt(discriminant)) / param.a);
	else
		return ((-param.b - sqrt(discriminant)) / param.a);
	(void)t0;
	(void)t1;
}

