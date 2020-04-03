/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_textures.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/18 13:27:55 by tim           #+#    #+#                 */
/*   Updated: 2020/04/02 19:51:58 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int    initialize_east(t_vars *t)
{
    t->ea->mlx_ea = mlx_init();
    if (!mlx_xpm_file_to_image(t->ea->mlx_ea, t->map->ea_texture, &t->ea->img_width_ea, &t->ea->img_height_ea))
    {
        write(1, "WRONG EA TEXTURE PATH\n", 22);
        return (1);
    }
    t->ea->img_ea = mlx_xpm_file_to_image(t->ea->mlx_ea, t->map->ea_texture, &t->ea->img_width_ea, &t->ea->img_height_ea);
	t->ea->addr_ea = mlx_get_data_addr(t->ea->img_ea, &t->ea->bits_per_pixel_ea,
	&t->ea->line_length_ea, &t->ea->endian_ea);
	return (0);
}

int    initialize_west(t_vars *t)
{
    t->we->mlx_we = mlx_init();
    if (!mlx_xpm_file_to_image(t->we->mlx_we, t->map->we_texture, &t->we->img_width_we, &t->we->img_height_we))
    {
        write(1, "WRONG WE TEXTURE PATH\n", 22);
        return (1);
    }
    t->we->img_we = mlx_xpm_file_to_image(t->we->mlx_we, t->map->we_texture, &t->we->img_width_we, &t->we->img_height_we);
	t->we->addr_we = mlx_get_data_addr(t->we->img_we, &t->we->bits_per_pixel_we,
	&t->we->line_length_we, &t->we->endian_we);
	return (0);
}

int    initialize_south(t_vars *t)
{
    t->so->mlx_so = mlx_init();
    if (!mlx_xpm_file_to_image(t->so->mlx_so, t->map->so_texture, &t->so->img_width_so, &t->so->img_height_so))
    {
        write(1, "WRONG SO TEXTURE PATH\n", 22);
        return (1);
    }
    t->so->img_so = mlx_xpm_file_to_image(t->so->mlx_so, t->map->so_texture, &t->so->img_width_so, &t->so->img_height_so);
	t->so->addr_so = mlx_get_data_addr(t->so->img_so, &t->so->bits_per_pixel_so,
	&t->so->line_length_so, &t->so->endian_so);
	return (0);
}

int    initialize_north(t_vars *t)
{
    t->no->mlx_no = mlx_init();
    if (!mlx_xpm_file_to_image(t->no->mlx_no, t->map->no_texture, &t->no->img_width_no, &t->no->img_height_no))
    {
        write(1, "WRONG NO TEXTURE PATH\n", 22);
        return (1);
    }
    t->no->img_no = mlx_xpm_file_to_image(t->no->mlx_no, t->map->no_texture, &t->no->img_width_no, &t->no->img_height_no);
	t->no->addr_no = mlx_get_data_addr(t->no->img_no, &t->no->bits_per_pixel_no,
	&t->no->line_length_no, &t->no->endian_no);
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
