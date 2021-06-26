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

// ATTENTION ! GET RID OF APPLE / LINUX CODE

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

static int change_cam(int keycode, t_rt *rt)
{
	int	LEFT_KEY;
	int	RIGHT_KEY;
	static int curr_cam = 0;

	#if __APPLE__
	LEFT_KEY = 123;
	RIGHT_KEY = 124;
	#else
	LEFT_KEY = 65361;
	RIGHT_KEY = 65363;

	#endif

    if (keycode == RIGHT_KEY)
    {
		if (curr_cam < rt->infos->scene->nb_cam - 1)
		{
			rt->curr.cam = rt->infos->scene->cam[curr_cam + 1];
			curr_cam += 1;
			if (curr_cam == rt->infos->scene->nb_cam - 1)
				printf("Last Camera\n");
			create_img(rt);
			return(yes);
		}
    }
	if (keycode == LEFT_KEY)
	{
	 	if (curr_cam > 0)
		{
			rt->curr.cam = rt->infos->scene->cam[curr_cam - 1];
			curr_cam -= 1;
			if (curr_cam == 0)
				printf("First Camera\n");
			create_img(rt);
			return(yes);
		}
	}
    return (no);
}

void	create_img(t_rt *rt)
{
    render_minirt(rt);

    //EVENTS (clean MAC/LINUX when pushing !!!)
    mlx_key_hook(rt->win, exit_and_free_ESC, rt); //escape clean exit
    #if __APPLE__
        mlx_hook(rt->win, 17, 0, exit_and_free_X, rt);
    #else
        mlx_hook(rt->win, 33, 0, exit_and_free_X, rt);
    #endif  

	if (rt->infos->scene->nb_cam > 1)
		mlx_key_hook(rt->win, change_cam, rt);

    //PUT IMG TO WINDOW
    mlx_put_image_to_window(rt->mlx, rt->win, rt->img.ptr, 0, 0);
}

static void	create_window(t_rt *rt)
{
	t_res   *res;

    res = &rt->infos->scene->res;
    rt->mlx = mlx_init();

    //OPEN WINDOW
    rt->win = mlx_new_window(rt->mlx, res->x, res->y, "I love bacon <3");
    rt->img.ptr = mlx_new_image(rt->mlx, res->x, res->y);
    rt->img.addr = mlx_get_data_addr(rt->img.ptr, &rt->img.bit_pix, &rt->img.line_l,
                                &rt->img.endian);
	return ;
}

void	start_minirt(t_rt *rt)
{
	if (rt->infos->scene->res.x == 0 || rt->infos->scene->res.y == 0)
		handle_error("parsing scene", rt->infos);
	if (rt->infos->scene->nb_cam == 0)
		handle_error("parsing scene", rt->infos);
	else
		rt->curr.cam = rt->infos->scene->cam[0];
	create_window(rt);
	create_img(rt);
    mlx_loop(rt->mlx);
}
