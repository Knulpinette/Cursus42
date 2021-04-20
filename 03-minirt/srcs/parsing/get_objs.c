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
	line = pass_spaces(line);
	obj->shape.sp.x = ft_atof(line);
	line = next_nbr(line);
	obj->shape.sp.y = ft_atof(line);
	line = next_nbr(line);
	obj->shape.sp.z = ft_atof(line);
	line = next_nbr(line);
	line = pass_spaces(line);
	obj->shape.sp.d = ft_atof(line);
	get_color(line, obj);
}

void	get_square(char *line, t_info *infos, int add_mem)
{
	t_obj	*obj;

	if (add_mem)
		infos->objs = add_mem_obj(infos->nb_objs, infos->objs);
	obj = &infos->objs[infos->nb_objs];
	obj->type = SQUARE;
	line = pass_spaces(line);
	obj->shape.sq.x = ft_atof(line);
	line = next_nbr(line);
	obj->shape.sq.y = ft_atof(line);
	line = next_nbr(line);
	obj->shape.sq.z = ft_atof(line);
	line = next_nbr(line);
	line = pass_spaces(line);
	obj->shape.sq.vec_x = ft_atof(line);
	line = next_nbr(line);
	obj->shape.sq.vec_y = ft_atof(line);
	line = next_nbr(line);
	obj->shape.sq.vec_z = ft_atof(line);
	line = next_nbr(line);
	line = pass_spaces(line);
	obj->shape.sq.side = ft_atof(line);
	get_color(line, obj);
}

void	get_plane(char *line, t_info *infos, int add_mem)
{
	t_obj	*obj;

	if (add_mem)
		infos->objs = add_mem_obj(infos->nb_objs, infos->objs);
	obj = &infos->objs[infos->nb_objs];
	obj->type = PLANE;
	line = pass_spaces(line);
	obj->shape.pl.x = ft_atof(line);
	line = next_nbr(line);
	obj->shape.pl.y = ft_atof(line);
	line = next_nbr(line);
	obj->shape.pl.z = ft_atof(line);
	line = next_nbr(line);
	line = pass_spaces(line);
	obj->shape.pl.vec_x = ft_atof(line);
	line = next_nbr(line);
	obj->shape.pl.vec_y = ft_atof(line);
	line = next_nbr(line);
	obj->shape.pl.vec_z = ft_atof(line);
	get_color(line, obj);
}

void	get_triangle(char *line, t_info *infos, int add_mem)
{
	t_obj	*obj;

	if (add_mem)
		infos->objs = add_mem_obj(infos->nb_objs, infos->objs);
	obj = &infos->objs[infos->nb_objs];
	obj->type = TRIANGLE;
	line = pass_spaces(line);
	obj->shape.tr.x0 = ft_atof(line);
	line = next_nbr(line);
	obj->shape.tr.x1 = ft_atof(line);
	line = next_nbr(line);
	obj->shape.tr.x2 = ft_atof(line);
	line = next_nbr(line);
	line = pass_spaces(line);
	get_triangle2(line, obj);
}

void	get_triangle2(char *line, t_obj *obj)
{
	obj->shape.tr.y0 = ft_atof(line);
	line = next_nbr(line);
	obj->shape.tr.y1 = ft_atof(line);
	line = next_nbr(line);
	obj->shape.tr.y2 = ft_atof(line);
	line = next_nbr(line);
	line = pass_spaces(line);
	obj->shape.tr.z0 = ft_atof(line);
	line = next_nbr(line);
	obj->shape.tr.z1 = ft_atof(line);
	line = next_nbr(line);
	obj->shape.tr.z2 = ft_atof(line);
	get_color(line, obj);
}

void	get_cylinder(char *line, t_info *infos, int add_mem)
{
	t_obj	*obj;

	if (add_mem)
		infos->objs = add_mem_obj(infos->nb_objs, infos->objs);
	obj = &infos->objs[infos->nb_objs];
	obj->type = CYLINDER;
	line = pass_spaces(line);
	obj->shape.cy.x = ft_atof(line);
	line = next_nbr(line);
	obj->shape.cy.y = ft_atof(line);
	line = next_nbr(line);
	obj->shape.cy.z = ft_atof(line);
	line = next_nbr(line);
	line = pass_spaces(line);
	obj->shape.cy.vec_x = ft_atof(line);
	line = next_nbr(line);
	obj->shape.cy.vec_y = ft_atof(line);
	line = next_nbr(line);
	obj->shape.cy.vec_z = ft_atof(line);
	line = next_nbr(line);
	line = pass_spaces(line);
	obj->shape.cy.h = ft_atof(line);
	line = next_nbr(line);
	line = pass_spaces(line);
	obj->shape.cy.d = ft_atof(line);
	get_color(line, obj);
}

void	get_color(char *line, t_obj *obj)
{
	line = next_nbr(line);
	line = pass_spaces(line);
	obj->color.r = ft_atoi(line);
	line = next_nbr(line);
	obj->color.g = ft_atoi(line);
	line = next_nbr(line);
	obj->color.b = ft_atoi(line);
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
		   infos->objs[infos->nb_objs].shape.tr.x0,
		   infos->objs[infos->nb_objs].shape.tr.x1,
		   infos->objs[infos->nb_objs].shape.tr.x2,
		   infos->objs[infos->nb_objs].shape.tr.y0,
		   infos->objs[infos->nb_objs].shape.tr.y1,
		   infos->objs[infos->nb_objs].shape.tr.y2,
			infos->objs[infos->nb_objs].shape.tr.z0,
			infos->objs[infos->nb_objs].shape.tr.z1,
			infos->objs[infos->nb_objs].shape.tr.z2,
		   infos->objs[infos->nb_objs].color.r,
		   infos->objs[infos->nb_objs].color.g,
		   infos->objs[infos->nb_objs].color.b);


	printf("   type = %i \n\
			x = %f \n\
			y = %f \n\
			z = %f \n\
			vec_x = %f \n\
			vec_y = %f \n\
			vec_z = %f \n\
			h = %f \n\
			d = %f \n\
			r, g, b = %i, %i, %i \n",
		   infos->objs[infos->nb_objs].type,
		   infos->objs[infos->nb_objs].shape.cy.x,
		   infos->objs[infos->nb_objs].shape.cy.y,
		   infos->objs[infos->nb_objs].shape.cy.z,
		   infos->objs[infos->nb_objs].shape.cy.vec_x,
		   infos->objs[infos->nb_objs].shape.cy.vec_y,
		   infos->objs[infos->nb_objs].shape.cy.vec_z,
			infos->objs[infos->nb_objs].shape.cy.h,
			infos->objs[infos->nb_objs].shape.cy.d,
		   infos->objs[infos->nb_objs].color.r,
		   infos->objs[infos->nb_objs].color.g,
		   infos->objs[infos->nb_objs].color.b);

*/
