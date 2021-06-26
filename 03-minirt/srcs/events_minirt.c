/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_minirt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 18:29:19 by osurcouf          #+#    #+#             */
/*   Updated: 2021/04/02 18:29:20 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int exit_and_free_X(t_rt *rt)
{
    printf("\n\n"COLOR_YELLOW"👋 Bye bye 👋\n\n");
    del_mem_infos(rt->infos);
    mlx_clear_window(rt->mlx, rt->win);
    mlx_destroy_window(rt->mlx, rt->win);
    exit(EXIT_SUCCESS);
    return (yes);
}

int change_cam(int keycode, t_rt *rt)
{
	static int curr_cam = 0;

    if (keycode == KEY_RIGHT)
    {
		if (curr_cam < rt->infos->scene->nb_cam - 1)
		{
			rt->curr.cam = rt->infos->scene->cam[curr_cam + 1];
			curr_cam += 1;
			create_img(rt);
			return(yes);
		}
    }
	if (keycode == KEY_LEFT)
	{
	 	if (curr_cam > 0)
		{
			rt->curr.cam = rt->infos->scene->cam[curr_cam - 1];
			curr_cam -= 1;
			create_img(rt);
			return(yes);
		}
	}
    return (no);
}