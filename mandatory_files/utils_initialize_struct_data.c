/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_initialize_struct_data.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vancitters <vancitters@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/25 08:36:51 by vancitters    #+#    #+#                 */
/*   Updated: 2020/04/25 08:38:22 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	initialize_texture_no(t_vars *t)
{
	t->no->img_h = 0;
	t->no->h1 = 0;
	t->no->half_res_h = 0;
	t->no->height_text = 0;
	t->no->y_count = 0;
	t->no->text_step = 0;
	t->no->pix_height = 0;
}

void	initialize_texture_so(t_vars *t)
{
	t->so->img_h = 0;
	t->so->h1 = 0;
	t->so->half_res_h = 0;
	t->so->height_text = 0;
	t->so->y_count = 0;
	t->so->text_step = 0;
	t->so->pix_height = 0;
	initialize_texture_no(t);
}

void	initialize_texture_ea(t_vars *t)
{
	t->ea->img_h = 0;
	t->ea->h1 = 0;
	t->ea->half_res_h = 0;
	t->ea->height_text = 0;
	t->ea->y_count = 0;
	t->ea->text_step = 0;
	t->ea->pix_height = 0;
	initialize_texture_so(t);
}

void	initialize_texture_we(t_vars *t)
{
	t->we->img_h = 0;
	t->we->h1 = 0;
	t->we->half_res_h = 0;
	t->we->height_text = 0;
	t->we->y_count = 0;
	t->we->text_step = 0;
	t->we->pix_height = 0;
	initialize_texture_ea(t);
}

void	initialize_texture_sp(t_vars *t)
{
	t->sp->count = 0;
	t->sp->height_text = 0;
	t->sp->y_count = 0;
	t->sp->img_h = 0;
	t->sp->h_res_h = 0;
	t->sp->h1 = 0;
	t->sp->step = 0.0;
	t->sp->sp_angle_l = 0.0;
	t->sp->sp_angle_r = 0.0;
	t->sp->pix_height = 0.0;
	t->sp->ray_start = 0.0;
	t->sp->sp_start = 0.0;
	t->sp->text_step = 0.0;
	t->sp->sp_step = 0.0;
	t->sp->ray_step = 0.0;
	t->sp->ray = 0.0;
	t->sp->i = 0.0;
	initialize_texture_we(t);
}

void	initialize_struct_details(t_vars *t)
{
	initialize_texture_sp(t);
}
