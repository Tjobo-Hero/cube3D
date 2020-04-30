/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_data.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: vancitters <vancitters@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/02 19:51:19 by vancitters    #+#    #+#                 */
/*   Updated: 2020/04/27 09:48:47 by tvan-cit      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	initialize_ray_struct(t_ray_data *r)
{
	r->temp_x = 0.0;
	r->temp_y = 0.0;
	r->ray_dir = 0.0;
	r->x_dir = 0.0;
	r->y_dir = 0.0;
	r->delta_x = 0.0;
	r->delta_y = 0.0;
	r->hit_x = 0.0;
	r->hit_y = 0.0;
	r->dist_x = 0.0;
	r->dist_y = 0.0;
	r->eucl_dist = 0.0;
	r->perp_dist = 0.0;
	r->pos_wall = 0.0;
	r->dist = 0.0;
	r->step_x = 0;
	r->step_y = 0;
	r->map_x = 0;
	r->map_y = 0;
	r->side = 0;
}

int		initialize_mlx(t_vars *t)
{
	t->mlx2 = mlx_init();
	t->img1 = mlx_new_image(t->mlx2, t->res3d_w, t->res3d_h);
	t->img2 = mlx_new_image(t->mlx2, t->res3d_w, t->res3d_h);
	t->addr1 = mlx_get_data_addr(t->img1, &t->bits_per_pixel2,
	&t->line_length2, &t->endian2);
	t->addr2 = mlx_get_data_addr(t->img2, &t->bits_per_pixel2,
	&t->line_length2, &t->endian2);
	t->win2 = mlx_new_window(t->mlx2, t->res3d_w, t->res3d_h,
	"WE'RE GONNA RULE THE WORLD, DON'T YOU KNOW, DON'T YOU KNOW");
	if (!t->mlx2 || !t->img1 || !t->img2 || !t->addr1 || !t->addr2 || !t->win2)
		return (put_str(">>>INITIALIZE MLX ERROR<<<", 1));
	return (0);
}

void	initialize_struct_data(t_vars *t)
{
	t->mid_line = fabs(1.0 / tan(M_PI / 6));
	t->sp->step = 0.001;
	t->addr_count = 0;
	t->move = 0.0;
	t->crab = 0.0;
	t->turn = 0.0;
}

int		resolution_check(t_vars *t, t_list *map)
{
	if (t->res3d_w > t->screen_x && map->save != 1)
		t->res3d_w = t->screen_x;
	if (t->res3d_h > t->screen_y && map->save != 1)
		t->res3d_h = t->screen_y;
	if (map->save == 1)
	{
		if (t->res3d_w > 16384)
		{
			write(1, ">>> MAX BPM WIDTH IS 16384---", 28);
			return (1);
		}
		if (t->res3d_h > 2000 || t->res3d_h > 2000)
			write(1, ">>>GRAB A CUP OF COFFEE, BMP IN THE MAKE<<<\n", 45);
	}
	return (0);
}

int		initialize_data(t_vars *t, t_list *map)
{
	set_tile_width_and_height(t);
	initialize_struct_details(t);
	mlx_get_screen_size(t->mlx2, &t->screen_x, &t->screen_y);
	if (!t->screen_x || !t->screen_y)
		return (put_str(">>>MLX GET_SCREEN_SIZE Error<<<", 1));
	initialize_struct_data(t);
	if (resolution_check(t, map))
		return (put_str(">>>RESOLUTION ERROR<<<", 1));
	if (initialize_mlx(t))
		return (put_str(">>>INITIALIZE ERROR<<<", 1));
	if (initialize_textures(t))
		return (1);
	if (initialize_sprites(t))
		return (1);
	return (0);
}
