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

/*
** 🦕
**
** function : Events in miniRT
**
**	1. Exit & Free
**		- Click on the cross on top of the window
**			and it will close all nice and pretty.
**	2. Change_cam
**		- By pressing the left or right arrow, you
**			can naviguate from one cam to the other.
**
**	Note : I want to make more events.
**			- Rotate camera (keyboard)
**			- Select & Move object (mouse)
**
** 🦕
*/

int	exit_and_free_X(t_rt *rt)
{
	printf("\n"COLOR_YELLOW"	👋 Bye bye 👋\n\n");
	del_mem_infos(rt->infos);
	mlx_clear_window(rt->mlx, rt->win);
	mlx_destroy_window(rt->mlx, rt->win);
	exit(EXIT_SUCCESS);
	return (yes);
}

int	change_cam(int keycode, t_rt *rt)
{
	static int	curr_cam = 0;

	if (keycode == KEY_RIGHT && curr_cam < rt->infos->scene->nb_cam - 1)
	{
		rt->curr.cam = rt->infos->scene->cam[curr_cam + 1];
		curr_cam += 1;
		create_img(rt);
		if (curr_cam == rt->infos->scene->nb_cam - 1)
			printf("🎥	Last Camera\n");
		return (yes);
	}
	if (keycode == KEY_LEFT && curr_cam > 0)
	{
		rt->curr.cam = rt->infos->scene->cam[curr_cam - 1];
		curr_cam -= 1;
		create_img(rt);
		if (curr_cam == 0)
			printf("🎥	First Camera\n");
		return (yes);
	}
	return (no);
}
