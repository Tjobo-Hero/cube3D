/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 15:52:28 by tvan-cit      #+#    #+#                 */
/*   Updated: 2020/04/22 12:07:29 by vancitters    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int		main(int argc, char **argv)
{
	t_list	map;
	t_vars	t;

	t.map = &map;
	write(1, ">>>CHECKING MAP & INFO<<<\n", 27);
	if (all_map_functions(&map, argc, argv))
		return (-1);
	draw_map(&t);
	maze(&map, &t);
	return (0);
}
