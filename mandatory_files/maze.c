/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   maze.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 11:31:23 by tvan-cit      #+#    #+#                 */
/*   Updated: 2020/04/14 12:59:58 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	rotate_player(float rot, t_vars *t)
{
	t->mid_ray += rot;
	t->mid_ray_x = sin(t->mid_ray);
	t->mid_ray_y = cos(t->mid_ray);
	if (t->mid_ray > TWOPI)
		t->mid_ray -= TWOPI;
	else if (t->mid_ray < 0)
		t->mid_ray += TWOPI;
}

int		lego(int key, t_vars *t)
{
	if (key == LOOK_LEFT || key == LOOK_RIGHT)
		t->turn = 0;
	else if (key == MOVE_UP || key == MOVE_UP2 ||
	key == MOVE_DOWN || key == MOVE_DOWN2)
		t->move = 0;
	else if (key == MOVE_RIGHT || key == MOVE_LEFT)
		t->crab = 0;
	return (key);
}

int		press(int key, t_vars *t)
{
	if (key == 53)
	{
		mlx_destroy_window(t->mlx2, t->win2);
		exit_program(t);
	}
	if (key == LOOK_LEFT)
		t->turn = 0.03;
	else if (key == LOOK_RIGHT)
		t->turn = -0.03;
	else if (key == MOVE_UP || key == MOVE_UP2)
		t->move = 0.06;
	else if (key == MOVE_DOWN || key == MOVE_DOWN2)
		t->move = -0.06;
	else if (key == MOVE_RIGHT)
		t->crab = 0.03;
	else if (key == MOVE_LEFT)
		t->crab = -0.03;
	return (key);
}

int		move(t_vars *t)
{
	t->addr_count++;
	screen_cleaner(t);
	rotate_player(t->turn, t);
	move_player(t, t->move);
	move_crab(t, t->crab);
	shoot_rays(t);
	if (t->addr_count % 2 == 0)
		mlx_put_image_to_window(t->mlx2, t->win2, t->img1, 0, 0);
	else
		mlx_put_image_to_window(t->mlx2, t->win2, t->img2, 0, 0);
	if (t->addr_count == 1000)
		t->addr_count = 0;
	return (1);
}

void	maze(t_list *map, t_vars *t)
{
	t_texture_no	no;
	t_texture_so	so;
	t_texture_we	we;
	t_texture_ea	ea;
	t_sprite		sp;

	t->we = &we;
	t->no = &no;
	t->so = &so;
	t->ea = &ea;
	t->sp = &sp;
	if (initialize_data(t, map))
	{
		write(1, ">>>INITIALIZE ERROR <<<\n", 25);
		exit_program(t);
	}
	shoot_rays(t);
	if (map->save == 1)
	{
		make_bmp("screenshot.bmp", t->addr1, t->res3d_w, t->res3d_h);
		exit_program(t);
	}
	mlx_put_image_to_window(t->mlx2, t->win2, t->img1, 0, 0);
	mlx_hook(t->win2, 2, 1L << 0, press, t);
	mlx_hook(t->win2, 3, 1L << 0, lego, t);
	mlx_hook(t->win2, 17, 1L << 17, leave_game, t);
	mlx_loop_hook(t->mlx2, move, t);
	mlx_loop(t->mlx2);
}
