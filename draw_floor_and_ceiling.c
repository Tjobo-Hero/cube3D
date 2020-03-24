/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_floor_and_ceiling.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/21 12:53:06 by tim            #+#    #+#                */
/*   Updated: 2020/03/21 13:31:55 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void    draw_floor(t_vars *t, int y_count, int x_count)
{
    y_count += t->res3d_h / 2;
    //   printf("y_count:%i\n", y_count);
    while (y_count < t->res3d_h)
    {
        my_mlx_pixel_put3d(t, x_count, y_count, t->map->f_hex);
        y_count++;
    }
}

void    draw_ceiling(t_vars *t, int y_count, int x_count)
{
    y_count++;
    y_count = t->res3d_h / 2 - y_count;
    while (y_count >= 0)
    {
        my_mlx_pixel_put3d(t, x_count, y_count, t->map->c_hex);
        y_count--;
    }
}

void    draw_floor_and_ceiling(t_vars *t, int y_count, int x_count)
{
    // printf("y_count:%i\n", y_count);
    // printf("x_count:%i\n", x_count);
    draw_floor(t, y_count, x_count);
    draw_ceiling(t, y_count, x_count);
}