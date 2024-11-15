/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeow <joeow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 22:10:21 by joeow             #+#    #+#             */
/*   Updated: 2024/11/16 02:07:33 by joeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	move_resume(t_map *map, int x, int y, int dir)
{
	if (dir == UP)
		y -= 1;
	if (dir == DOWN)
		y += 1;
	if (dir == LEFT)
		x -= 1;
	if (dir == RIGHT)
		x += 1;
	if (map->array[y][x] == 'E' && map->c == 0)
		ft_won(map);
	if (map->array[y][x] == 'C')
	{
		map->array[y][x] = '0';
		map->c--;
	}
}

void	move_up(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (y > 0 && map->array[y - 1][x] != '1')
	{
		move_resume(map, x, y, UP);
		if (map->array[y - 1][x] == 'E' && (map->c != 0 || map->exit == 1))
			return ;
		map->moves++;
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.floor,
			x * IMG_PXL, y * IMG_PXL);
		map->array[y][x] = '0';
		y--;
		print_movements(map);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.floor,
			x * IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.player,
			x * IMG_PXL, y * IMG_PXL);
		map->array[y][x] = 'P';
		map->player.x = x;
	}
}

void	move_left(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (x > 0 && map->array[y][x - 1] != '1')
	{
		move_resume(map, x, y, LEFT);
		if (map->array[y][x - 1] == 'E' && (map->c != 0 || map->exit == 1))
			return ;
		map->moves++;
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.floor,
			x * IMG_PXL, y * IMG_PXL);
		map->array[y][x] = '0';
		x--;
		print_movements(map);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.floor,
			x * IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.player,
			x * IMG_PXL, y * IMG_PXL);
		map->array[y][x] = 'P';
		map->player.y = y;
		map->player.x = x;
	}
}

void	move_down(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (y < map->y && map->array[y + 1][x] != '1')
	{
		move_resume(map, x, y, DOWN);
		if (map->array[y + 1][x] == 'E' && (map->c != 0 || map->exit == 1))
			return ;
		map->moves++;
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.floor,
			x * IMG_PXL, y * IMG_PXL);
		map->array[y][x] = '0';
		y++;
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.floor,
			x * IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.player,
			x * IMG_PXL, y * IMG_PXL);
		map->array[y][x] = 'P';
		print_movements(map);
		map->player.y = y;
		map->player.x = x;
	}
}

void	move_right(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (x < map->x && map->array[y][x + 1] != '1')
	{
		move_resume(map, x, y, RIGHT);
		if (map->array[y][x + 1] == 'E' && (map->c != 0 || map->exit == 1))
			return ;
		map->moves++;
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.floor,
			x * IMG_PXL, y * IMG_PXL);
		map->array[y][x] = '0';
		x++;
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.floor,
			x * IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.player,
			x * IMG_PXL, y * IMG_PXL);
		map->array[y][x] = 'P';
		print_movements(map);
		map->player.y = y;
		map->player.x = x;
	}
}