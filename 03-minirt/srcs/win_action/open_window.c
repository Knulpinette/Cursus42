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

typedef struct  s_data {
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}               t_data;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;
    
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void    draw_rectangle(t_data *img)
{
    int x;
    int y;

    x = 10;
    y = 10;
    while (x++ < 400)
        my_mlx_pixel_put(img, x, y, 0x00FF0000);
    while (y++ < 400)
        my_mlx_pixel_put(img, x, y, 0x00FF0000);
    while (x-- > 10)
        my_mlx_pixel_put(img, x, y, 0x00FF0000);
    while (y-- > 10)
        my_mlx_pixel_put(img, x, y, 0x00FF0000);
}

void    draw_triangle(t_data *img)
{
    int x;
    int y;
    //int z;

    x = 100;
    y = 100;
   // z = 500;
    while (x++ < 500)
        my_mlx_pixel_put(img, x, y, 0x0000FF00);
    while (x-- > 300 && y++ < 500)
        my_mlx_pixel_put(img, x, y, 0x0000FF00);
    while (x-- > 100 && y-- > 100)
        my_mlx_pixel_put(img, x, y, 0x0000FF00);
}

void    draw_circle(t_data *img)
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
}

int     main(int argc, char **argv)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;
    t_info	infos;
    int     error;

    if (argc < 2)
        return (-1);
    if (argc == 2)
    {
        error = open_fd(argv[1], &infos);
        if (!error)
            return (-1);
    }
    mlx = mlx_init();
    //scene = get_scene();
    //objs = get_objs();
    //PARSE with GNL + OPEN/READ and ARGUMENTS with miniRT
    //OPEN WINDOW
    mlx_win = mlx_new_window(mlx, 1920, 1080, "I love bacon <3");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                &img.endian);
    //RENDER SHAPES => DRAWING THEM WITH TRIG
    draw_rectangle(&img);
    draw_triangle(&img);
    draw_circle(&img);
    //PUT IMG TO WINDOW
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
    //IF ACTIONS
    //EXIT WINDOW
}
