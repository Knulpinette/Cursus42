/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:55:35 by osurcouf          #+#    #+#             */
/*   Updated: 2021/04/02 18:29:14 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** 🦕
** function : open a window and push pixels onto it
** 🦕
*/

static void	render_minirt(t_rt *rt)
{
	int	x;
	int	y;
	t_scene *scene;
	
	scene = rt->infos->scene;
	y = 0;
	x = 0;
	while (y < scene->res.y)
	{
		x = 0;
		while (x < scene->res.x)
		{
			gen_cam_ray(x, y, rt);
			check_if_it_hits_object(rt);
			get_pixel_color(rt);
			my_mlx_pixel_put(&rt->img, x, y, rt->curr.pix_color);
			x++;
		}
		y++;
	}
}

void	create_img(t_rt *rt)
{
    render_minirt(rt);
    mlx_hook(rt->win, DESTROY, 0, exit_and_free_X, rt);
	if (rt->infos->scene->nb_cam > 1)
		mlx_key_hook(rt->win, change_cam, rt);
	if (rt->infos->nb_objs == no)
	{
		printf(""COLOR_YELLOW"Fair warning ✋\n");
		printf(""COLOR_WHITE"This program is cooler with objects 🪑 🛀\n");
	}
    mlx_put_image_to_window(rt->mlx, rt->win, rt->img.ptr, 0, 0);
}

static void	create_window(t_rt *rt)
{
	t_res   *res;

    res = &rt->infos->scene->res;
    rt->mlx = mlx_init();
    rt->win = mlx_new_window(rt->mlx, res->x, res->y, "miniRT");
    rt->img.ptr = mlx_new_image(rt->mlx, res->x, res->y);
    rt->img.addr = mlx_get_data_addr(rt->img.ptr, &rt->img.bit_pix, 
									&rt->img.line_l, &rt->img.endian);
	return ;
}

void	start_minirt(t_rt *rt)
{
	if (rt->infos->scene->res.x == 0 || rt->infos->scene->res.y == 0)
		handle_error("📏 Careful, resolution is 0.\n", rt->infos);
	if (rt->infos->scene->nb_cam == 0)
		handle_error("🎥 There are no cameras.\n", rt->infos);
	else
		rt->curr.cam = rt->infos->scene->cam[0];
	printf(""COLOR_LIGHT_CYAN"\n🖼️ Starting miniRT 🖼️"COLOR_END"\n\n");
	printf(""COLOR_WHITE"");
	if (rt->infos->scene->nb_cam > 1)
		printf("🎥 [To Change Cameras] : Press 🢀 or 🢂\n");
	printf(""COLOR_END"");
	create_window(rt);
	create_img(rt);
    mlx_loop(rt->mlx);
}
