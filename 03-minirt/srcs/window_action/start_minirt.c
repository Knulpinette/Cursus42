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

void	start_minirt(t_rt *rt)
{
    t_res   *res;
	// SPHERE AND PLANE => ACCORDING TO WHERE THE CAMERA IS ? (POV BASICALLY)

    res = &rt->infos->scene->res;
    rt->mlx = mlx_init();

    //OPEN WINDOW
    rt->win = mlx_new_window(rt->mlx, res->x, res->y, "I love bacon <3");
    rt->img.ptr = mlx_new_image(rt->mlx, res->x, res->y);
    rt->img.addr = mlx_get_data_addr(rt->img.ptr, &rt->img.bit_pix, &rt->img.line_l,
                                &rt->img.endian);

	//HANDLE RENDERING
    render_minirt(rt);

    //EVENTS (clean that up when pushing !!!)
    mlx_key_hook(rt->win, exit_and_free_ESC, rt); //escape clean exit
    #if __APPLE__
        mlx_hook(rt->win, 17, 0, exit_and_free_X, rt);
    #else
        mlx_hook(rt->win, 33, 0, exit_and_free_X, rt);
    #endif  

    //PUT IMG TO WINDOW
    mlx_put_image_to_window(rt->mlx, rt->win, rt->img.ptr, 0, 0);
    mlx_loop(rt->mlx);
}
