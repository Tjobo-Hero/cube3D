/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_sprites.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 16:35:53 by tim            #+#    #+#                */
/*   Updated: 2020/03/23 16:36:50 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void    draw_sprites(t_vars *t)
{
    char   *color;
    float   pix_height;
	int     y_count;
    float   text_step;
    int     height_text;

    pix_height = 1.0 / t->sp->eucl_dist[t->sp->count]; // nog geen perp
    height_text = (pix_height * t->res3d_h) / 2.0;
	if (pix_height > 1.0)
		pix_height = 0.999999;
	pix_height = (pix_height * t->res3d_h) / 2.0;
	y_count = 0;
    text_step = ((t->sp->img_height - 1.0) / 2.0) / height_text; // new
	while (y_count <= (int)pix_height) // Kan mis gaan door de + 1;
	{
        color = t->sp->addr + (((t->sp->img_height / 2) + (int)(text_step * y_count)) * t->sp->line_length + (int)(t->sp->pos_wall[t->sp->count] * t->sp->img_width) *
        (t->sp->bits_per_pixel / 8));
        if (*(unsigned int *)color != 0x00000000)
            my_mlx_pixel_put3d(t, t->x_count, (t->res3d_h / 2) + y_count, *(unsigned int*)color);
        color = t->sp->addr + (((t->sp->img_height / 2) - (int)(text_step * y_count)) * t->sp->line_length + (int)(t->sp->pos_wall[t->sp->count] * t->sp->img_width) *
        (t->sp->bits_per_pixel / 8));
        if (*(unsigned int *)color != 0x00000000)
		    my_mlx_pixel_put3d(t, t->x_count, (t->res3d_h / 2) - y_count, *(unsigned int*)color);
        y_count++;
    }
    if (t->res3d_h % 2 == 0)
    {
        color = t->sp->addr + (((t->sp->img_height / 2) - (int)(text_step * y_count)) * t->sp->line_length + (int)(t->sp->pos_wall[t->sp->count] * t->sp->img_width) *
        (t->sp->bits_per_pixel / 8));
        if (*(unsigned int *)color != 0x00000000)
		    my_mlx_pixel_put3d(t, t->x_count, (t->res3d_h / 2) - y_count, *(unsigned int*)color);
    }
}