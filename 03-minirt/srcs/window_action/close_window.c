/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 18:29:19 by osurcouf          #+#    #+#             */
/*   Updated: 2021/04/02 18:29:20 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// ATTENTION ! GET RID OF APPLE / LINUX CODE


int exit_and_free_X(t_rt *rt)
{
    del_mem_infos(rt->infos);
    mlx_clear_window(rt->mlx, rt->win);
    mlx_destroy_window(rt->mlx, rt->win);
    exit(EXIT_SUCCESS);
    return (yes);
}

int exit_and_free_ESC(int keycode, t_rt *rt)
{
	int	ESC_KEY;

	#if __APPLE__
	ESC_KEY = 53;
	#else
	ESC_KEY = 65307;
	#endif

    if (keycode == ESC_KEY)
    {
        del_mem_infos(rt->infos);
        mlx_clear_window(rt->mlx, rt->win);
        mlx_destroy_window(rt->mlx, rt->win);
        exit(EXIT_SUCCESS);
		return(yes);
    }
    return (no);
}