/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_player.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 15:08:57 by tvan-cit      #+#    #+#                 */
/*   Updated: 2020/04/14 21:30:45 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	move_player(t_vars *t, float move)
{
	float temp_x;
	float temp_y;

	temp_x = t->x;
	temp_y = t->y;
	t->x += sin(t->mid_ray) * move;
	if (t->map->map_2d[(int)t->y][(int)t->x] == '1')
		t->x = temp_x;
	t->y += cos(t->mid_ray) * move;
	if (t->map->map_2d[(int)t->y][(int)t->x] == '1')
		t->y = temp_y;
}

void	move_crab(t_vars *t, float move)
{
	float temp_x;
	float temp_y;
	float x_dir;
	float y_dir;

	temp_x = t->x;
	temp_y = t->y;
	x_dir = sin(t->mid_ray + M_PI / 2);
	y_dir = cos(t->mid_ray + M_PI / 2);
	t->x += x_dir * move;
	if (t->map->map_2d[(int)t->y][(int)t->x] == '1')
		t->x = temp_x;
	t->y += y_dir * move;
	if (t->map->map_2d[(int)t->y][(int)t->x] == '1')
		t->y = temp_y;
}
