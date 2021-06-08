/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 22:20:47 by osurcouf          #+#    #+#             */
/*   Updated: 2021/05/27 22:20:49 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*void    draw_circle(t_img *img)
{
    int x;
    int y;
    int r;
    double x1;
    double y1;
    double angle;
    static const double PI = 3.1415926535;

    r = 30;
    x = 250;
    y = 250;
    angle = 0;
    while (angle <= 360)
    {
        angle = angle + 1;
        x1 = r * cos(angle * PI / 180);
        y1 = r * sin(angle * PI / 180);
        my_mlx_pixel_put(img, (x + x1), (y + y1), 0x0000FF);
    }
}*/

float	cylinder(t_ray *ray, t_rec *curr)
{

	// find t1 & t2
	// for At2 + Bt + C = 0;
	// if result > 0, it's a possible intersection.
	// find t3 && t4
	// then do calculation with candidates


	t_params param;
	t_vec	A;
	t_vec	B;
	t_cylinder *cy;

	cy = &curr->obj.shape.cy;

	A.x = ray->dir.x - (cy->orient.x * dot_product(ray->dir, cy->orient));
	A.y = ray->dir.y - (cy->orient.y * dot_product(ray->dir, cy->orient));
	A.x = ray->dir.z - (cy->orient.z * dot_product(ray->dir, cy->orient));

	B.x = (ray->ori.x - cy->point.x) - 
		(cy->orient.x * 
		(dot_product(substract(ray->dir, cy->point), cy->orient)));
	B.y = (ray->ori.y - cy->point.y) - 
		(cy->orient.y * 
		(dot_product(substract(ray->dir, cy->point), cy->orient)));
	B.z = (ray->ori.z - cy->point.z) - 
		(cy->orient.z * 
		(dot_product(substract(ray->dir, cy->point), cy->orient)));
	

	param.a = dot_product(A, A);
	param.b = 2 * dot_product(A, B);
	param.c = dot_product(B, B) - (cy->radius * cy->radius);

	if (!solve_quadratic(param, &curr->t0, &curr->t1))
		return (0);
	return (solve_quadratic(param, &curr->t0, &curr->t1));

	//figure out how to handle the t0 and t1
	//figure out how to check t, the extremities and figure out how to insert the height into all this
	
}

/*
ctp = substract(point, cylinder.p);
	normal = substract(ctp, v3_multiply(cylinder.normal,
										dot_product(cylinder.normal, ctp)));
	normalize_vector(&normal);*/