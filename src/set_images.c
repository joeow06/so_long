/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeow <joeow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:31:13 by jow               #+#    #+#             */
/*   Updated: 2024/11/15 20:54:04 by joeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void convert_image(t_map *map)
{
	int	a;

	a = IMG_PXL;
	map->img.wall = mlx_xpm_file_to_image(map->mlx_ptr, "pictures/wall.xpm",
			&a, &a);
	map->img.player = mlx_xpm_file_to_image(map->mlx_ptr, "pictures/player.xpm",
			&a, &a);
	map->img.collectible = mlx_xpm_file_to_image(map->mlx_ptr,
			"pictures/collectible.xpm", &a, &a);
	map->img.floor = mlx_xpm_file_to_image(map->mlx_ptr, "pictures/floor.xpm",
			&a, &a);
	map->img.exit = mlx_xpm_file_to_image(map->mlx_ptr, "pictures/exit.xpm",
			&a, &a);
}
