/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_sprite.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 11:02:35 by tim            #+#    #+#                */
/*   Updated: 2020/03/23 12:12:34 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void    initialize_sprites(t_vars *t)
{
    t->sp->mlx = mlx_init();
    if (!mlx_xpm_file_to_image(t->sp->mlx, t->map->sprite_texture, &t->sp->img_width, &t->sp->img_height))
    {
        write(1, "WRONG SPRITE PATH\n", 18);
        exit_program(t);
    }
    t->sp->img = mlx_xpm_file_to_image(t->sp->mlx, t->map->sprite_texture, &t->sp->img_width, &t->sp->img_height);
	t->sp->addr = mlx_get_data_addr(t->sp->img, &t->sp->bits_per_pixel,
	&t->sp->line_length, &t->sp->endian);
}