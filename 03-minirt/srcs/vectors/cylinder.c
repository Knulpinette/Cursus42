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
/*
float	intersect_cylinder(t_ray *ray, t_obj *obj)
{

	// find t1 & t2
	// for At2 + Bt + C = 0;
	// if result > 0, it's a possible intersection.
	// find t3 && t4
	// then do calculation with candidates


	t_vec	A; // position cross product
	t_vec	B; // direction cross product
	int	a;
	int	b;
	int	t;
	int	d;
	int	k;

	A.x = (ray->ori.x - obj->shape.cy.point.x) * obj->shape.cy.orient.x;
	A.y = (ray->ori.y - obj->shape.cy.point.y) * obj->shape.cy.orient.y;
	A.y = (ray->ori.z - obj->shape.cy.point.z) * obj->shape.cy.orient.z;

	B.x = ray->dir.x * obj->shape.cy.orient.x;
	B.y = ray->dir.y * obj->shape.cy.orient.y;
	B.y = ray->dir.z * obj->shape.cy.orient.z;

	a = (

	);

	b = (

	);

	t = A / B;
	d = ;

}




	a_sqrt = substract(ray.direction,
								v3_multiply(cylinder.normal,
								dot_product(ray.direction, cylinder.normal)));
	a = dot_product(a_sqrt, a_sqrt);
	right = substract(substract(ray.origin, cylinder.p),
						v3_multiply(cylinder.normal,
							dot_product(substract(ray.origin, cylinder.p),
							cylinder.normal)));
	b = 2 * dot_product(a_sqrt, right);
	c = dot_product(right, right) - (cylinder.radius * cylinder.radius);
	if (!solve_quadratic(new_qparams(a, b, c), t0, t1))
		return (0);
	return (1);

tmp = (A.B * A.B) - (B.B * A.A) - 
(R2 * (cyl.orient . cyl.orient));


		𝑡=𝐴′⋅(𝐴′−𝐵′)/(𝐴′−𝐵′)⋅(𝐴′−𝐵′)*/