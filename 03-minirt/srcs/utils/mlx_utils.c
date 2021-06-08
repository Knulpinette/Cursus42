/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:18:58 by osurcouf          #+#    #+#             */
/*   Updated: 2021/04/28 14:19:04 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void    my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    char    *dst;
    
    dst = img->addr + (y * img->line_l + x * (img->bit_pix / 8));
    *(unsigned int*)dst = color;
}
