/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeow <joeow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:03:09 by jow               #+#    #+#             */
/*   Updated: 2024/11/16 02:37:31 by joeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int on_keypress(int keysym, t_map *map)
{
	scan_player(map);
	if (keysym == XK_Escape)
	{
		ft_printf("Escape key pressed. Exiting...\n");
		close_game(map);
	}
	else if (keysym == XK_w)
	{
		move_up(map);
		for (int i = 0; map->array[i]; i++)
			printf("%s\n", map->array[i]);
	}
	else if (keysym == XK_a)
	{
		move_left(map);
		for (int i = 0; map->array[i]; i++)
			printf("%s\n", map->array[i]);
	}
	else if (keysym == XK_d)
	{
		move_right(map);
		for (int i = 0; map->array[i]; i++)
			printf("%s\n", map->array[i]);
	}
	else if (keysym == XK_s)
	{
		move_down(map);
		for (int i = 0; map->array[i]; i++)
			printf("%s\n", map->array[i]);
	}
	printf("x: %d\n", map->player.x);
	printf("y: %d\n", map->player.y);
	return (0);
}

void	map_init(t_map *map, char *filename)
{
	map->filename = filename;
	map->moves = 0;
	map->e = 0;
	map->c = 0;
	map->p = 0;
	map->y = 0;
	map->player.y = 0;
	map->player.x = 0;
	map->exit = 0;
}

int main(int argc, char **argv)
{
	t_map	map;

	if (argc == 2)
	{
		map_init(&map, argv[1]);
		map_checker(&map);
		map.mlx_ptr = mlx_init();
		map.win_ptr = mlx_new_window(map.mlx_ptr, map.x
				* IMG_PXL, map.y * IMG_PXL, WND_NAME);
		convert_image(&map);
		map_printer(&map);
		mlx_hook(map.win_ptr, 17, 0, close_game, &map);
		mlx_key_hook(map.win_ptr, on_keypress, &map);
		mlx_loop(map.mlx_ptr);
	}
	else
	{
		write(2, "Error: Wrong Arguments\n", 24);
		return (1);
	}
}
