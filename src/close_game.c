/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeow <joeow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 02:26:29 by joeow             #+#    #+#             */
/*   Updated: 2024/11/16 15:32:49 by joeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_won(t_map *map)
{
	int	i;

	i = 0;
	map->exit = 1;
	map->moves++;
	print_movements(map);
	ft_printf("\nYou won!\n");
	if (map->array)
	{
		while (map->array[i])
		{
			free(map->array[i]);
			i++;
		}
		free(map->array);
	}
	exit(EXIT_SUCCESS);
}

int	close_game(t_map *map)
{
	mlx_destroy_image(map->mlx_ptr, map->img.wall);
	mlx_destroy_image(map->mlx_ptr, map->img.player);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	mlx_destroy_display(map->mlx_ptr);
	free(map->mlx_ptr);
	exit(0);
	return (0);
}
