/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_def.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:48:14 by osurcouf          #+#    #+#             */
/*   Updated: 2021/04/02 16:48:16 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_DEF_H
# define STRUCT_DEF_H

# include "minirt.h"

/*
** ELEMENTS OF OBJS STRUCT
*/

typedef struct s_sphere
{
	float	x;
	float	y;
	float	z;
	float	d;
}				t_sphere;

typedef struct s_plane
{
	float	x;
	float	y;
	float	z;
	float	vec_x;
	float	vec_y;
	float	vec_z;
}				t_plane;

typedef struct s_square
{
	float	x;
	float	y;
	float	z;
	float	vec_x;
	float	vec_y;
	float	vec_z;
	float	side;
}				t_square;

typedef struct s_cylinder
{
	float	x;
	float	y;
	float	z;
	float	vec_x;
	float	vec_y;
	float	vec_z;
	float	h;
	float	d;
}				t_cylinder;

typedef struct s_triangle
{
	float	x0;
	float	x1;
	float	x2;
	float	y0;
	float	y1;
	float	y2;
	float	z0;
	float	z1;
	float	z2;
}				t_triangle;

typedef struct s_color
{
	int		t;
	int		r;
	int		g;
	int 	b;
	int		color;
}				t_color;

enum e_obj 
{
	SPHERE = 1,
	PLANE,
	SQUARE,
	CYLINDER,
	TRIANGLE,
};

typedef union u_type 
{
	t_sphere	sp;
	t_plane		pl;
	t_square	sq;
	t_cylinder	cy;
	t_triangle	tr;
}				t_type;

/*
** OBJECT STRUCT
*/

typedef struct s_obj
{
	int		type;  //enum return so we know what type of union we have/get
	t_type	shape; //union to allocate only one type of memory
	t_color	color; //struct
	void	*next; //ptr to chained list
}				t_obj;

/*
** ELEMENTS OF SCENE SETUP STRUCT
*/

typedef struct s_res
{
	int	x;
	int	y;
}				t_res;
	
typedef struct 	s_ambient
{
	float		r;
	t_color	color;
}				t_ambient;

typedef struct s_camera
{
	float	x;
	float	y;
	float	z;
	float	vec_x;
	float	vec_y;
	float	vec_z;
	int		FOV;
}				t_camera;

typedef struct s_light
{
	int		x;
	int		y;
	int		z;
	float	bright;
	t_color	color;
}				t_light;

/*
** SCENE SETUP STRUCT
*/

typedef struct s_scene
{
	t_res		res;
	t_ambient	amb;
	t_camera	cam;
	t_light		light;
}				t_scene;

/*
** INFO STRUCT
*/

typedef struct s_info
{
	t_scene		scene;
	t_obj		objs;
}				t_info;

#endif