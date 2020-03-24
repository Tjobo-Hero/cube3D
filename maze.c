/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   maze.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 11:31:23 by tvan-cit       #+#    #+#                */
/*   Updated: 2020/03/23 12:11:42 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"
#define LOOK_LEFT 123
#define LOOK_RIGHT 124
#define MOVE_UP 13
#define MOVE_DOWN 1
#define MOVE_RIGHT 0
#define MOVE_UP2 126
#define MOVE_DOWN2 125
#define MOVE_LEFT 2

int		my_mlx_pixel_put2(t_vars *t, int x, int y, int color)
{
	char	*dst;

	if (t->map->map_2d[y / t->tile_height][x / t->tile_width] == '1' ||
	t->map->map_2d[y / t->tile_height][x / t->tile_width] == '2')
		return (0);
	dst = t->addr + (y * t->line_length + x *
	(t->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
	return (1);
}

int		my_mlx_pixel_put(t_vars *t, int x, int y, int color)
{
	char	*dst;

	dst = t->addr + (y * t->line_length + x *
	(t->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
	return (1);
}

void	make_sprite(t_vars *t, int x, int y)
{
	int tile_width;
	int tile_height;
	int begin_x;

	x = t->tile_width * x;
	y = t->tile_height * y;
	tile_width = t->tile_width + x;
	tile_height = t->tile_height + y;
	begin_x = x;
	while (y <= tile_height)
	{
		while (x <= tile_width)
		{
			my_mlx_pixel_put(t, x, y, 0xC000FF);
			x++;
		}
		x = begin_x;
		y++;
	}
}

void	make_square(t_vars *t, int x, int y)
{
	int tile_width;
	int tile_height;
	int begin_x;

	x = t->tile_width * x;
	y = t->tile_height * y;
	tile_width = t->tile_width + x;
	tile_height = t->tile_height + y;
	begin_x = x;
	while (y <= tile_height)
	{
		while (x <= tile_width)
		{
			my_mlx_pixel_put(t, x, y, 0x08FF80);
			x++;
		}
		x = begin_x;
		y++;
	}
}

void	draw_ray(float ray_angle, int color, t_vars *t)
{
	t_ray_data	r;
	float		temp_x;
	float		temp_y;

	r.ray_dir = ray_angle;
	r.x_dir = sin(r.ray_dir);
	r.y_dir = cos(r.ray_dir);
	temp_y = (t->y) * t->tile_height;
	temp_x = (t->x) * t->tile_width;
	while (my_mlx_pixel_put2(t, temp_x, temp_y, color))
	{
		temp_x += r.x_dir;
		temp_y += r.y_dir;
	}
	if (color != 0x00000000)
	{
		find_wall(t, &r);
		//  printf("11hi\n");
		// if (!(r.side == 0 && r.ray_dir < 1))
			// main_world(t, &r);
	}
}

void	shoot_rays(t_vars *t, int color)
{
	float 	start;
	float 	ray;
	float 	increment;
	float 	mid_line;
	
	mid_line = fabs(1.0 / tan(M_PI / 6));
	increment = 2.0 / t->res3d_w; /// later veranderen naar res_3d_w
	start = -1;
	t->x_count = 0;
	while (start <= 1)
	{
		ray = t->mid_ray - atan(start / mid_line);
		if (ray > (2 * M_PI))
			ray -= (2 * M_PI);
		if (ray < 0)
			ray += (2 * M_PI);
		draw_ray(ray, color, t);
		// printf("12hi\n");
		start += increment;
		// printf("13hi\n");
		t->x_count++;
		// printf("14hi\n");
	}
}

int		make_me(int color, t_vars *t)
{
	// printf("21hi\n");
	my_mlx_pixel_put(t, t->x * t->tile_width, t->y * t->tile_height, color);
	// printf("20hi\n");
	shoot_rays(t, color);
	// printf("15hi\n");
	return (0);
}

void	draw_grid(t_vars *t)
{
	int x;
	int y;
	int temp;

	y = 0;
	x = 0;
	temp = t->tile_width;
	make_me(0x000000FF, t);
	while (x < t->map->column_count)
	{
		y = 0;
		while (y < t->map->res_h)
		{
			my_mlx_pixel_put(t, temp, y, 0x0008FF80);
			y++;
		}
		temp += t->tile_width;
		x++;
	}
	temp = t->tile_height;
	x = 0;
	while (x < t->map->row_count)
	{
		y = 0;
		while (y < t->map->res_w)
		{
			my_mlx_pixel_put(t, y, temp, 0x0008FF80);
			y++;
		}
		temp += t->tile_height;
		x++;
	}
}

void	rotate_player(float rot, t_vars *t)
{
	// printf("17hi\n");
	shoot_rays(t, 0x00000000);
	// printf("16hi\n");
	t->mid_ray += rot;
	t->mid_ray_x = sin(t->mid_ray);
	t->mid_ray_y = cos(t->mid_ray);
	if (t->mid_ray > (2 * M_PI))
		t->mid_ray -= (2 * M_PI);
	if (t->mid_ray < 0)
		t->mid_ray += (2 * M_PI);
	// printf("MID_ray:%f\n", t->mid_ray);
	//shoot_rays(t, color);
}

void	draw_map(t_vars *t)
{
	int x;
	int y;

	y = 0;
	while (y < t->map->row_count)
	{
		x = 0;
		while (t->map->map_2d[y][x] != '\0')
		{
			if (t->map->map_2d[y][x] == '1')
				make_square(t, x, y);
			if (t->map->map_2d[y][x] == '2')
				make_sprite(t, x, y);
			if (t->map->map_2d[y][x] == 'N' || t->map->map_2d[y][x] == 'S' ||
			t->map->map_2d[y][x] == 'E' || t->map->map_2d[y][x] == 'W')
			{
				set_player_direction(t, t->map->map_2d[y][x]);
				t->x = x + 0.5;
				t->y = y + 0.5;
			}
			x++;
		}
		y++;
	}
	draw_grid(t);
}

int		move(int key, t_vars *t)
{
	screen_cleaner(t);
	rotate_player(0, t);
	if (key == 53)
	{
		mlx_destroy_window(t->mlx, t->win);
		exit(0);
	}
	else if (key == LOOK_LEFT)
		rotate_player(0.09, t);
	else if (key == LOOK_RIGHT)
		rotate_player(-0.09, t);
	else if (key == MOVE_UP || key == MOVE_UP2)
		move_player(t, 0.1);
	else if (key == MOVE_DOWN || key == MOVE_DOWN2)
		move_player(t, -0.1);
	else if (key == MOVE_RIGHT)
		move_crab(t, 0.1);
	else if (key == MOVE_LEFT)
		move_crab(t, -0.1);
	draw_grid(t);
	mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
	mlx_put_image_to_window(t->mlx2, t->win2, t->img2, 0, 0);
	return (key);
}

void		set_tile_width_and_height(t_vars *t)
{
	t->res3d_w = t->map->res_w;
	t->res3d_h = t->map->res_h;
	t->tile_height = 0;
	t->tile_width = (t->map->res_w / t->map->column_count);
	t->tile_height = (t->map->res_h / t->map->row_count);
	if (t->tile_width > t->tile_height)
	{
		t->tile_width = t->tile_height;
		t->map->res_w = t->tile_width * t->map->column_count;
	}
	else
	{
		t->tile_height = t->tile_width;
		t->map->res_h = t->tile_height * t->map->row_count;
	}
} 

void	maze(t_list *map)
{
	t_vars	t;
	t_texture_no 	no;
	t_texture_so 	so;
	t_texture_we 	we;
	t_texture_ea 	ea;
	t_sprite		sp;

	t.we = &we;
	t.no = &no;
	t.so = &so;
	t.ea = &ea;
	t.map = map;
	t.sp = &sp;
	initialize_textures(&t);
	initialize_sprites(&t);
	set_tile_width_and_height(&t);
	t.mlx = mlx_init();
	t.win = mlx_new_window(t.mlx, t.map->res_w, t.map->res_h + 1, "YES YES");
	t.img = mlx_new_image(t.mlx, t.map->res_w, t.map->res_h + 1);
	t.addr = mlx_get_data_addr(t.img, &t.bits_per_pixel,
	&t.line_length, &t.endian);
	t.mlx2 = mlx_init();
	t.win2 = mlx_new_window(t.mlx2, t.res3d_w, t.res3d_h, "WE'RE GONNA RULE THE WORLD, DON'T YOU KNOW, DON'T YOU KNOW");
	t.img2 = mlx_new_image(t.mlx2, t.res3d_w, t.res3d_h);
	t.addr2 = mlx_get_data_addr(t.img2, &t.bits_per_pixel2,
	&t.line_length2, &t.endian2);
	draw_map(&t);
	mlx_put_image_to_window(t.mlx, t.win, t.img, 0, 0);
	mlx_hook(t.win, 2, 1L << 0, move, &t);
	mlx_loop(t.mlx);
}

