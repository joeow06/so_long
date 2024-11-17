/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeow <joeow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:34:26 by joeow             #+#    #+#             */
/*   Updated: 2024/11/17 14:23:33 by joeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	on_keypress(int keysym, t_map *map)
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
	}
	else if (keysym == XK_a)
	{
		move_left(map);
	}
	else if (keysym == XK_d)
	{
		move_right(map);
	}
	else if (keysym == XK_s)
	{
		move_down(map);
	}
	printf("x: %d\n", map->player.x);
	printf("y: %d\n", map->player.y);
	return (0);
}
