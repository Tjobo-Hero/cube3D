/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_sprite.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 11:02:35 by tim           #+#    #+#                 */
/*   Updated: 2020/04/08 10:26:36 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int		initialize_sprites(t_vars *t)
{
	t->sp->mlx = mlx_init();
	if (!mlx_xpm_file_to_image(t->sp->mlx, t->map->sprite_texture,
	&t->sp->img_width, &t->sp->img_height))
	{
		write(1, "WRONG SPRITE PATH\n", 18);
		return (1);
	}
	t->sp->img = mlx_xpm_file_to_image(t->sp->mlx, t->map->sprite_texture,
	&t->sp->img_width, &t->sp->img_height);
	t->sp->addr = mlx_get_data_addr(t->sp->img, &t->sp->bits_per_pixel,
	&t->sp->line_length, &t->sp->endian);
	return (0);
}