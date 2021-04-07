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

void get_sphere(char *line, t_info *infos)
{
	infos->objs.type = SPHERE;
	line = pass_spaces(line);
	infos->objs.shape.sp.x = ft_atof(line);
	line = next_nbr(line);
	infos->objs.shape.sp.y = ft_atof(line);
	line = next_nbr(line);
	infos->objs.shape.sp.z = ft_atof(line);
	line = next_nbr(line);
	line = pass_spaces(line);
	infos->objs.shape.sp.d = ft_atof(line);
	line = next_nbr(line);
	line = pass_spaces(line);
	infos->objs.color.r = ft_atoi(line);
	line = next_nbr(line);
	infos->objs.color.g = ft_atoi(line);
	line = next_nbr(line);
	infos->objs.color.b = ft_atoi(line);
}

void get_square(char *line, t_info *infos)
{
	infos->objs.type = SQUARE;
	line = pass_spaces(line);
	infos->objs.shape.sq.x = ft_atof(line);
	line = next_nbr(line);
	infos->objs.shape.sq.y = ft_atof(line);
	line = next_nbr(line);
	infos->objs.shape.sq.z = ft_atof(line);
	line = next_nbr(line);
	line = pass_spaces(line);
	infos->objs.shape.sq.vec_x = ft_atof(line);
	line = next_nbr(line);
	infos->objs.shape.sq.vec_y = ft_atof(line);
	line = next_nbr(line);
	infos->objs.shape.sq.vec_z = ft_atof(line);
	line = next_nbr(line);
	line = pass_spaces(line);
	infos->objs.shape.sq.side = ft_atof(line);
	line = next_nbr(line);
	line = pass_spaces(line);
	infos->objs.color.r = ft_atoi(line);
	line = next_nbr(line);
	infos->objs.color.g = ft_atoi(line);
	line = next_nbr(line);
	infos->objs.color.b = ft_atoi(line);
}

void get_plane(char *line, t_info *infos)
{
	infos->objs.type = PLANE;
	line = pass_spaces(line);
	infos->objs.shape.pl.x = ft_atof(line);
	line = next_nbr(line);
	infos->objs.shape.pl.y = ft_atof(line);
	line = next_nbr(line);
	infos->objs.shape.pl.z = ft_atof(line);
	line = next_nbr(line);
	line = pass_spaces(line);
	infos->objs.shape.pl.vec_x = ft_atof(line);
	line = next_nbr(line);
	infos->objs.shape.pl.vec_y = ft_atof(line);
	line = next_nbr(line);
	infos->objs.shape.pl.vec_z = ft_atof(line);
	line = next_nbr(line);
	line = pass_spaces(line);
	infos->objs.color.r = ft_atoi(line);
	line = next_nbr(line);
	infos->objs.color.g = ft_atoi(line);
	line = next_nbr(line);
	infos->objs.color.b = ft_atoi(line);
}

void get_triangle(char *line, t_info *infos)
{
	infos->objs.type = TRIANGLE;
	line = pass_spaces(line);
	infos->objs.shape.tr.x0 = ft_atof(line);
	line = next_nbr(line);
	infos->objs.shape.tr.x1 = ft_atof(line);
	line = next_nbr(line);
	infos->objs.shape.tr.x2 = ft_atof(line);
	line = next_nbr(line);
	line = pass_spaces(line);
	infos->objs.shape.tr.y0 = ft_atof(line);
	line = next_nbr(line);
	infos->objs.shape.tr.y1 = ft_atof(line);
	line = next_nbr(line);
	infos->objs.shape.tr.y2 = ft_atof(line);
	line = next_nbr(line);
	line = pass_spaces(line);
	infos->objs.shape.tr.z0 = ft_atof(line);
	line = next_nbr(line);
	infos->objs.shape.tr.z1 = ft_atof(line);
	line = next_nbr(line);
	infos->objs.shape.tr.z2 = ft_atof(line);
	line = next_nbr(line);
	line = pass_spaces(line);
	infos->objs.color.r = ft_atoi(line);
	line = next_nbr(line);
	infos->objs.color.g = ft_atoi(line);
	line = next_nbr(line);
	infos->objs.color.b = ft_atoi(line);
}

void get_cylinder(char *line, t_info *infos)
{
	infos->objs.type = CYLINDER;
	line = pass_spaces(line);
	infos->objs.shape.cy.x = ft_atof(line);
	line = next_nbr(line);
	infos->objs.shape.cy.y = ft_atof(line);
	line = next_nbr(line);
	infos->objs.shape.cy.z = ft_atof(line);
	line = next_nbr(line);
	line = pass_spaces(line);
	infos->objs.shape.cy.vec_x = ft_atof(line);
	line = next_nbr(line);
	infos->objs.shape.cy.vec_y = ft_atof(line);
	line = next_nbr(line);
	infos->objs.shape.cy.vec_z = ft_atof(line);
	line = next_nbr(line);
	line = pass_spaces(line);
	infos->objs.shape.cy.h = ft_atof(line);
	line = next_nbr(line);
	line = pass_spaces(line);
	infos->objs.shape.cy.d = ft_atof(line);
	line = next_nbr(line);
	line = pass_spaces(line);
	infos->objs.color.r = ft_atoi(line);
	line = next_nbr(line);
	infos->objs.color.g = ft_atoi(line);
	line = next_nbr(line);
	infos->objs.color.b = ft_atoi(line);
}

/*
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
		   infos->objs.type,
		   infos->objs.shape.cy.x,
		   infos->objs.shape.cy.y,
		   infos->objs.shape.cy.z,
		   infos->objs.shape.cy.vec_x,
		   infos->objs.shape.cy.vec_y,
		   infos->objs.shape.cy.vec_z,
			infos->objs.shape.cy.h,
			infos->objs.shape.cy.d,
		   infos->objs.color.r,
		   infos->objs.color.g,
		   infos->objs.color.b);
*/
