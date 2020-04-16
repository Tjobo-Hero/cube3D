/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_sprites.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 16:35:53 by tim            #+#    #+#                */
/*   Updated: 2020/04/16 19:21:11 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	draw_sprites_2(t_vars *t, char *color)
{
	if (t->res3d_h % 2 == 0)
	{
		color = t->sp->addr + ((t->sp->img_h - (int)(t->sp->text_step *
		t->sp->y_count)) * t->sp->line_length + t->sp->h1);
		if (*(unsigned int *)color != 0x00000000)
			my_mlx_pixel_put3d(t, t->x_count, t->sp->h_res_h - t->sp->y_count,
			*(unsigned int*)color);
	}
}

void	draw_sprite_calculations(t_vars *t)
{
	t->sp->pix_height = (t->sp->pix_height * t->res3d_h) / 2.0;
	t->sp->y_count = 0;
	t->sp->img_h = (t->sp->img_height / 2);
	t->sp->h_res_h = (t->res3d_h / 2);
	t->sp->h1 = (int)(t->sp->pos_wall[t->sp->count] * t->sp->img_width) *
	(t->sp->bits_per_pixel / 8);
	t->sp->text_step = ((t->sp->img_height - 1.0) / 2.0) / t->sp->height_text;
}

void	draw_sprites(t_vars *t)
{
	char	*color;

	t->sp->pix_height = 1.0 / t->sp->eucl_dist[t->sp->count];
	t->sp->height_text = (t->sp->pix_height * t->res3d_h) / 2.0;
	if (t->sp->pix_height > 1.0)
		t->sp->pix_height = 0.999999;
	draw_sprite_calculations(t);
	while (t->sp->y_count <= (int)t->sp->pix_height)
	{
		color = t->sp->addr + ((t->sp->img_h + (int)(t->sp->text_step *
		t->sp->y_count)) * t->sp->line_length + t->sp->h1);
		if (*(unsigned int *)color != 0x00000000 && t->sp->h_res_h +
		t->sp->y_count < t->res3d_h)
			my_mlx_pixel_put3d(t, t->x_count, t->sp->h_res_h + t->sp->y_count,
			*(unsigned int*)color);
		color = t->sp->addr + ((t->sp->img_h - (int)(t->sp->text_step *
		t->sp->y_count)) * t->sp->line_length + t->sp->h1);
		if (*(unsigned int *)color != 0x00000000)
			my_mlx_pixel_put3d(t, t->x_count, t->sp->h_res_h - t->sp->y_count,
			*(unsigned int*)color);
		t->sp->y_count++;
	}
	draw_sprites_2(t, color);
}
