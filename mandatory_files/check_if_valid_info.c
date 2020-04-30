/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_if_valid_info.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 15:58:33 by tvan-cit      #+#    #+#                 */
/*   Updated: 2020/04/27 10:02:31 by tvan-cit      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int		check_rgb(t_list *map)
{
	if (map->f_color_blue > 255 || map->f_color_green > 255 ||
	map->f_color_red > 255)
	{
		write(1, ">>>FLOOR---", 12);
		return (1);
	}
	if (map->c_color_blue > 255 || map->c_color_green > 255 ||
	map->c_color_red > 255)
	{
		write(1, ">>>CEILING---", 14);
		return (1);
	}
	if (map->f_color_blue < 0 || map->f_color_green < 0
	|| map->f_color_red < 0 || map->c_color_blue < 0 ||
	map->c_color_green < 0 || map->c_color_red < 0)
	{
		write(1, ">>>MISSING FLOOR OR CEILING COLOR---", 36);
		return (1);
	}
	return (0);
}

void	put_color_to_hex(t_list *map)
{
	map->f_hex = 0;
	map->c_hex = 0;
	map->f_hex = map->f_hex + (map->f_color_blue % 16);
	map->f_hex = map->f_hex + ((map->f_color_blue / 16)
	* 16);
	map->f_hex = map->f_hex + (map->f_color_green % 16)
	* pow(16, 2);
	map->f_hex = map->f_hex + (map->f_color_green / 16)
	* pow(16, 3);
	map->f_hex = map->f_hex + (map->f_color_red % 16)
	* pow(16, 4);
	map->f_hex = map->f_hex + (map->f_color_red / 16)
	* pow(16, 5);
	map->c_hex = map->c_hex + (map->c_color_blue % 16);
	map->c_hex = map->c_hex + ((map->c_color_blue / 16)
	* 16);
	map->c_hex = map->c_hex + (map->c_color_green % 16)
	* pow(16, 2);
	map->c_hex = map->c_hex + (map->c_color_green / 16)
	* pow(16, 3);
	map->c_hex = map->c_hex + (map->c_color_red % 16) *
	pow(16, 4);
	map->c_hex = map->c_hex + (map->c_color_red / 16) *
	pow(16, 5);
}

int		check_if_valid_info(t_list *map)
{
	if (!map->so_texture || !map->no_texture ||
	!map->we_texture || !map->ea_texture
	|| !map->sprite_texture)
		return (put_str(">>>MISSING TEXTURE<<<\n", 1));
	if (map->res_h < 25 || map->res_w < 25 || !map->res_h || !map->res_w)
		return (put_str(">>>RESOLUTION ERROR, KEEP IT >= 25<<<\n", 1));
	if (check_rgb(map))
		return (put_str(">>>WRONG RGB COLOR<<<\n", 1));
	put_color_to_hex(map);
	return (put_str(">>>INFO IS VALID<<<\n", 0));
}
