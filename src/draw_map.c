/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeow <joeow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:29:51 by joeow             #+#    #+#             */
/*   Updated: 2024/11/16 16:17:17 by joeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	convert_image(t_map *map)
{
	int	a;

	a = IMG_PXL;
	map->img.wall = mlx_xpm_file_to_image(map->mlx_ptr, "pictures/wall.xpm",
			&a, &a);
	map->img.player = mlx_xpm_file_to_image(map->mlx_ptr,
			"pictures/player.xpm", &a, &a);
	map->img.collectible = mlx_xpm_file_to_image(map->mlx_ptr,
			"pictures/collectible.xpm", &a, &a);
	map->img.floor = mlx_xpm_file_to_image(map->mlx_ptr, "pictures/floor.xpm",
			&a, &a);
	map->img.exit = mlx_xpm_file_to_image(map->mlx_ptr, "pictures/exit.xpm",
			&a, &a);
}

static void	map_type(t_map *map, int x, int y)
{
	int	type;

	type = map->array[y / IMG_PXL][x / IMG_PXL];
	if (type == 'C' || type == 'P' || type == 'E' || type == '0')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->img.floor, x, y);
	if (type == 'C')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->img.collectible, x, y);
	else if (type == 'P')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->img.player, x, y);
	else if (type == 'E')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->img.exit, x, y);
	else if (type == '1')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->img.wall, x, y);
}

void	draw_map(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->y)
	{
		while (x < map->x)
		{
			map_type(map, x * IMG_PXL, y * IMG_PXL);
			x++;
		}
		x = 0;
		y++;
	}
}

void	print_movements(t_map *map)
{
	char	*move;

	move = ft_itoa(map->moves);
	write(1, "\r", 1);
	write(1, "\x1b[33;01m", 9);
	write(1, move, ft_strlen(move));
	write(1, "\x1b[0m", 5);
	write(1, " movements", 11);
	free(move);
}
