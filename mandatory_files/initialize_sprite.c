/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_sprite.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 11:02:35 by tim           #+#    #+#                 */
/*   Updated: 2020/04/23 16:58:38 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int		initialize_sprites(t_vars *t)
{
	t->sp->mlx = mlx_init();
	if (!mlx_xpm_file_to_image(t->sp->mlx, t->map->sprite_texture,
	&t->sp->img_width, &t->sp->img_height))
		return (put_str(">>>WRONG SPRITE PATH<<<\n", 1));
	t->sp->img = mlx_xpm_file_to_image(t->sp->mlx, t->map->sprite_texture,
	&t->sp->img_width, &t->sp->img_height);
	t->sp->addr = mlx_get_data_addr(t->sp->img, &t->sp->bits_per_pixel,
	&t->sp->line_length, &t->sp->endian);
	if (!t->sp->mlx || !t->sp->img || !t->sp->addr)
		return (put_str(">>>ERROR INITIALIZE SPRITE PATH<<<\n", 1));
	return (0);
}
