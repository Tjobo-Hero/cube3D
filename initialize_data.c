/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_data.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: vancitters <vancitters@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/02 19:51:19 by vancitters    #+#    #+#                 */
/*   Updated: 2020/04/03 15:08:14 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int		initialize_mlx(t_vars *t)
{
	t->mlx2 = mlx_init();
	t->img1 = mlx_new_image(t->mlx2, t->res3d_w, t->res3d_h);
	t->img2 = mlx_new_image(t->mlx2, t->res3d_w, t->res3d_h);
	t->addr1 = mlx_get_data_addr(t->img1, &t->bits_per_pixel2, &t->line_length2, &t->endian2);
	t->addr2 = mlx_get_data_addr(t->img2, &t->bits_per_pixel2, &t->line_length2, &t->endian2);
	t->win2 = mlx_new_window(t->mlx2, t->res3d_w, t->res3d_h, "WE'RE GONNA RULE THE WORLD, DON'T YOU KNOW, DON'T YOU KNOW");
	return (0);
}

int		initialize_data(t_vars *t, t_list *map)
{
	set_tile_width_and_height(t);
	mlx_get_screen_size(t->mlx2, &t->screen_x, &t->screen_y);
	if (t->res3d_w > t->screen_x && map->save != 1)
		t->res3d_w = t->screen_x;
	if (t->res3d_h > t->screen_y && map->save != 1)
		t->res3d_h = t->screen_y;
	if (t->res3d_w < 25)
		t->res3d_w = 25;
	if (t->res3d_h < 25)
		t->res3d_h = 25;
	t->mid_line = fabs(1.0 / tan(M_PI / 6));
	t->sp->step = 0.001;
	t->addr_count = 0;
	t->move = 0.0;
	t->crab = 0.0;
	t->turn = 0.0;
	if (initialize_mlx(t))
		return (1);
	if (initialize_textures(t))
		return (1);
	if (initialize_sprites(t))
		return (1);
	return (0);
}