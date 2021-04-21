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

void    my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
    char    *dst;
    
    dst = img->addr + (y * img->line_l + x * (img->bit_pix / 8));
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

static int close_win(int keycode, t_rt *rt)
{
    if (keycode == 65307)
    {
        del_mem_infos(rt->infos);
        mlx_clear_window(rt->mlx, rt->win);
        mlx_destroy_window(rt->mlx, rt->win);
        exit(0);
    }
    return (1);
}

int     main(int argc, char **argv)
{
    t_rt    rt;

    ft_bzero(&rt, sizeof(t_rt));
    if (argc < 2)
        return (-1);
    if (argc > 2)
        return (-1);
    
    get_infos(argv[1], &rt);
    //start_minirt();
// SPHERE AND PLANE => ACCORDING TO WHERE THE CAMERA IS ? (POV BASICALLY)

    rt.mlx = mlx_init();

    //OPEN WINDOW
    rt.win = mlx_new_window(rt.mlx, 1920, 1080, "I love bacon <3");
    rt.data.img = mlx_new_image(rt.mlx, 1920, 1080);
    rt.data.addr = mlx_get_data_addr(rt.data.img, &rt.data.bit_pix, &rt.data.line_l,
                                &rt.data.endian);

    //RENDER SHAPES => DRAWING THEM WITH TRIG
    draw_rectangle(&rt.data);
    draw_triangle(&rt.data);
    draw_circle(&rt.data);

    //EVENTS
    mlx_key_hook(rt.win, close_win, &rt); //escape clean exit
    #if __APPLE__
        mlx_hook(rt.win, 17, 0, exit_and_free, &rt);
    #else
        mlx_hook(rt.win, 33, 0, exit_and_free, &rt);
    #endif  

    //PUT IMG TO WINDOW
    mlx_put_image_to_window(rt.mlx, rt.win, rt.data.img, 0, 0);
    mlx_loop(rt.mlx);
}
