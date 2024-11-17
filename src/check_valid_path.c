/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeow <joeow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:39:56 by joeow             #+#    #+#             */
/*   Updated: 2024/11/17 14:25:21 by joeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	scan_player(t_map *map)
{
	map->player.y = 0;
	map->player.x = 0;
	while (map->player.y < map->y)
	{
		while (map->player.x < map->x)
		{
			if (map->array[map->player.y][map->player.x] == 'P')
				break ;
			map->player.x++;
		}
		if (map->array[map->player.y][map->player.x] == 'P')
			break ;
		map->player.x = 0;
		map->player.y++;
	}
}

void	move_on_paths(int x, int y, t_map *map)
{
	char	type;

	type = map->copy[y][x];
	if (type == 'C')
	{
		map->c_check -= 1;
		map->copy[y][x] = '1';
	}
	else if (type == 'E')
	{
		map->e_check -= 1;
		map->copy[y][x] = '1';
	}
	else if (type == '0' || type == 'P')
		map->copy[y][x] = '1';
	else
		return ;
	move_on_paths(x + 1, y, map);
	move_on_paths(x - 1, y, map);
	move_on_paths(x, y + 1, map);
	move_on_paths(x, y - 1, map);
}

void	check_valid_path(t_map *map)
{
	map->c_check = map->c;
	map->e_check = map->e;
	scan_player(map);
	move_on_paths(map->player.x, map->player.y, map);
	if (map->c_check != 0 || map->e_check >= map->e)
	{
		write(2, "Error: No Valid Path\n", 21);
		ft_exit_free(map);
		exit(EXIT_FAILURE);
	}
}
