/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 18:22:30 by osurcouf          #+#    #+#             */
/*   Updated: 2021/04/02 18:22:32 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_sphere(char *line, t_info *infos, int add_mem)
{
	t_obj	*obj;

	if (add_mem)
		infos->objs = add_mem_obj(infos->nb_objs, infos->objs);
	obj = &infos->objs[infos->nb_objs];
	obj->type = SPHERE;
	line = get_vector(line, &obj->shape.sp.point);
	line = next_nbr(line);
	line = pass_spaces(line);
	obj->shape.sp.d = ft_atof(line);
	get_color(line, &obj->color);
}

void	get_square(char *line, t_info *infos, int add_mem)
{
	t_obj	*obj;

	if (add_mem)
		infos->objs = add_mem_obj(infos->nb_objs, infos->objs);
	obj = &infos->objs[infos->nb_objs];
	obj->type = SQUARE;
	line = get_vector(line, &obj->shape.sq.point);
	line = next_nbr(line);
	line = get_vector(line, &obj->shape.sq.orient);
	line = next_nbr(line);
	line = pass_spaces(line);
	obj->shape.sq.side = ft_atof(line);
	get_color(line, &obj->color);
}

void	get_plane(char *line, t_info *infos, int add_mem)
{
	t_obj	*obj;

	if (add_mem)
		infos->objs = add_mem_obj(infos->nb_objs, infos->objs);
	obj = &infos->objs[infos->nb_objs];
	obj->type = PLANE;
	line = get_vector(line, &obj->shape.pl.point);
	line = next_nbr(line);
	line = get_vector(line, &obj->shape.pl.orient);
	get_color(line, &obj->color);
}

void	get_triangle(char *line, t_info *infos, int add_mem)
{
	t_obj	*obj;

	if (add_mem)
		infos->objs = add_mem_obj(infos->nb_objs, infos->objs);
	obj = &infos->objs[infos->nb_objs];
	obj->type = TRIANGLE;
	line = get_vector(line, &obj->shape.tr.point_x);
	line = next_nbr(line);
	line = get_vector(line, &obj->shape.tr.point_y);
	line = next_nbr(line);
	line = get_vector(line, &obj->shape.tr.point_z);
	get_color(line, &obj->color);
}

void	get_cylinder(char *line, t_info *infos, int add_mem)
{
	t_obj	*obj;

	if (add_mem)
		infos->objs = add_mem_obj(infos->nb_objs, infos->objs);
	obj = &infos->objs[infos->nb_objs];
	obj->type = CYLINDER;
	line = get_vector(line, &obj->shape.cy.point);
	line = next_nbr(line);
	line = get_vector(line, &obj->shape.cy.orient);
	line = next_nbr(line);
	line = pass_spaces(line);
	obj->shape.cy.h = ft_atof(line);
	line = next_nbr(line);
	line = pass_spaces(line);
	obj->shape.cy.d = ft_atof(line);
	get_color(line, &obj->color);
}

/*

		printf("   type = %i \n\
			x0 = %f \n\
			x1 = %f \n\
			x2 = %f \n\
			y0 = %f \n\
			y1 = %f \n\
			y2 = %f \n\
			z0 = %f \n\
			z1 = %f \n\
			z2 = %f \n\
			r, g, b = %i, %i, %i \n",
		   infos->objs[infos->nb_objs].type,
		   infos->objs[infos->nb_objs].shape.tr.point_x.x,
		   infos->objs[infos->nb_objs].shape.tr.point_x.y,
		   infos->objs[infos->nb_objs].shape.tr.point_x.z,
		   infos->objs[infos->nb_objs].shape.tr.point_y.x,
		   infos->objs[infos->nb_objs].shape.tr.point_y.y,
		   infos->objs[infos->nb_objs].shape.tr.point_y.z,
		   infos->objs[infos->nb_objs].shape.tr.point_z.x,
		   infos->objs[infos->nb_objs].shape.tr.point_z.y,
		   infos->objs[infos->nb_objs].shape.tr.point_z.z,
		   infos->objs[infos->nb_objs].color.r,
		   infos->objs[infos->nb_objs].color.g,
		   infos->objs[infos->nb_objs].color.b);


	printf("   type = %i \n\
			x = %f \n\
			y = %f \n\
			z = %f \n\
			vec.x = %f \n\
			vec.y = %f \n\
			vec.z = %f \n\
			h = %f \n\
			d = %f \n\
			r, g, b = %i, %i, %i \n",
		   infos->objs[infos->nb_objs].type,
		   infos->objs[infos->nb_objs].shape.cy.x,
		   infos->objs[infos->nb_objs].shape.cy.y,
		   infos->objs[infos->nb_objs].shape.cy.z,
		   infos->objs[infos->nb_objs].shape.cy.vec.x,
		   infos->objs[infos->nb_objs].shape.cy.vec.y,
		   infos->objs[infos->nb_objs].shape.cy.vec.z,
			infos->objs[infos->nb_objs].shape.cy.h,
			infos->objs[infos->nb_objs].shape.cy.d,
		   infos->objs[infos->nb_objs].color.r,
		   infos->objs[infos->nb_objs].color.g,
		   infos->objs[infos->nb_objs].color.b);

*/
