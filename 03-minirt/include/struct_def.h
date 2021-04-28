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
** VECTOR STRUCT
*/

typedef struct	s_vec
{
	float	x;
	float	y;
	float	z;
}				t_vec;

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
	t_vec	vec;
}				t_plane;

typedef struct s_square
{
	float	x;
	float	y;
	float	z;
	t_vec	vec;
	float	side;
}				t_square;

typedef struct s_cylinder
{
	float	x;
	float	y;
	float	z;
	t_vec	vec;
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
	t_vec	position;
	t_vec	orient;
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
	int			nb_cam;
	t_camera	*cam;
	int			nb_light;
	t_light		*light;
}				t_scene;

/*
** INFO STRUCT
*/

typedef struct s_info
{
	t_scene		*scene;
	int			nb_objs;
	t_obj		*objs;
}				t_info;

/*
** RAY STRUCT
*/

typedef struct	s_ray 
{
	t_vec	ori; //origin
	t_vec	dir; //direction
}				t_ray;


/*
** MLX STRUCTS
*/

typedef struct  s_img
{
    void    *ptr;
    char    *addr;
    int     bit_pix; // bits_per_pixels
    int     line_l; //line_length
    int     endian; // endian
}               t_img;

typedef struct  s_rt
{
        void    	*mlx;
        void    	*win;
        t_img	  	img;
		t_info		*infos;
		t_vec		pix;
		t_ray		ray;
		int			sky_light;

}               t_rt;

#endif