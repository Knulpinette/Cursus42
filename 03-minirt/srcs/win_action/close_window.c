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

int destroy_window(t_mlx *mlx)
{
    mlx_clear_window(mlx->mlx, mlx->win);
    mlx_destroy_window(mlx->mlx, mlx->win);
    exit(0);
    return (1);
}