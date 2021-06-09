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

void	start_minirt(t_rt *rt)
{
    t_res   *res;

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
