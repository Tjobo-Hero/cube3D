/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_textures.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/18 13:27:55 by tim           #+#    #+#                 */
/*   Updated: 2020/04/03 16:07:04 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int    initialize_east(t_vars *t)
{
    t->ea->mlx = mlx_init();
    if (!mlx_xpm_file_to_image(t->ea->mlx, t->map->ea_texture, &t->ea->img_width, &t->ea->img_height))
    {
        write(1, "WRONG EA TEXTURE PATH\n", 22);
        return (1);
    }
    t->ea->img = mlx_xpm_file_to_image(t->ea->mlx, t->map->ea_texture, &t->ea->img_width, &t->ea->img_height);
	t->ea->addr = mlx_get_data_addr(t->ea->img, &t->ea->bits_per_pixel,
	&t->ea->line_length, &t->ea->endian);
	return (0);
}

int    initialize_west(t_vars *t)
{
    t->we->mlx = mlx_init();
    if (!mlx_xpm_file_to_image(t->we->mlx, t->map->we_texture, &t->we->img_width, &t->we->img_height))
    {
        write(1, "WRONG WE TEXTURE PATH\n", 22);
        return (1);
    }
    t->we->img = mlx_xpm_file_to_image(t->we->mlx, t->map->we_texture, &t->we->img_width, &t->we->img_height);
	t->we->addr = mlx_get_data_addr(t->we->img, &t->we->bits_per_pixel,
	&t->we->line_length, &t->we->endian);
	return (0);
}

int    initialize_south(t_vars *t)
{
    t->so->mlx = mlx_init();
    if (!mlx_xpm_file_to_image(t->so->mlx, t->map->so_texture, &t->so->img_width, &t->so->img_height))
    {
        write(1, "WRONG SO TEXTURE PATH\n", 22);
        return (1);
    }
    t->so->img = mlx_xpm_file_to_image(t->so->mlx, t->map->so_texture, &t->so->img_width, &t->so->img_height);
	t->so->addr = mlx_get_data_addr(t->so->img, &t->so->bits_per_pixel,
	&t->so->line_length, &t->so->endian);
	return (0);
}

int    initialize_north(t_vars *t)
{
    t->no->mlx = mlx_init();
    if (!mlx_xpm_file_to_image(t->no->mlx, t->map->no_texture, &t->no->img_width, &t->no->img_height))
    {
        write(1, "WRONG NO TEXTURE PATH\n", 22);
        return (1);
    }
    t->no->img = mlx_xpm_file_to_image(t->no->mlx, t->map->no_texture, &t->no->img_width, &t->no->img_height);
	t->no->addr = mlx_get_data_addr(t->no->img, &t->no->bits_per_pixel,
	&t->no->line_length, &t->no->endian);
	return (0);
}

int    initialize_textures(t_vars *t)
{
    if (initialize_east(t))
		return (1);
	if (initialize_north(t))
		return (1);
	if (initialize_south(t))
		return (1);
	if (initialize_west(t))
		return (1);
   return (0);
}
