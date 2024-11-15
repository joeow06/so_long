/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeow <joeow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:34:31 by jow               #+#    #+#             */
/*   Updated: 2024/11/13 15:15:51 by joeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	check_filename(t_map *map)
{
	int	len;

	len = ft_strlen(map->filename);
	if (map->filename[len - 1] != 'r')
		error_map_exit(1);
	if (map->filename[len - 2] != 'e')
		error_map_exit(1);
	if (map->filename[len - 3] != 'b')
		error_map_exit(1);
	if (map->filename[len - 4] != '.')
		error_map_exit(1);
	if (!map->filename[len - 5])
		error_map_exit(1);
}

void	check_wall(t_map *map)
{
	int	x;
	int	y;

	if (!map || !map->array || map->y < 1 || map->x < 1)
		error_wall(map);
	x = 0;
	while (x < map->x && map->array[0][x] == '1')
		x++;
	if (x != map->x)
		error_wall(map);
	y = 1;
	while (y < map->y - 1)
	{
		if (map->array[y][0] != '1' || map->array[y][map->x - 1] != '1')
			error_wall(map);
		y++;
	}
	x = 0;
	while (x < map->x && map->array[map->y - 1][x] == '1')
		x++;
	if (x != map->x)
		error_wall(map);
}

void	checker_params(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->array[y][x] == 'C')
				map->c += 1;
			else if (map->array[y][x] == 'E')
				map->e += 1;
			else if (map->array[y][x] == 'P')
				map->p += 1;
			else if (map->array[y][x] != '0' && map->array[y][x] != '1')
				error_map_elements(map);
			x++;
		}
		y++;
	}
	if (map->c < 1 || map->e < 1 || map->p != 1)
		error_map_elements(map);
}

static void	check_size(t_map *map)
{
	size_t	len;
	int		i;

	len = ft_strlen(map->array[0]);
	i = 1;
	while (map->array[i])
	{
		if (ft_strlen(map->array[i]) != len)
			error_map_size(map);
		else
			i++;
	}
}

void	map_checker(t_map *map)
{
	check_filename(map);
	map_to_array(map);
	check_size(map);
	check_wall(map);
	checker_params(map);
	check_valid_path(map);
	ft_free_array(map->copy, map->y);
}
