/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeow <joeow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:53:30 by jow               #+#    #+#             */
/*   Updated: 2024/11/17 15:59:10 by joeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	error_map_exit(int i)
{
	if (i == 1)
		write(1, "Error: Input MAP as XXX.ber\n", 28);
	else if (i == 2)
		write(1, "Error: File does not exist\n", 27);
	else if (i == 3)
		write(1, "Error: Map is Empty\n", 20);
	exit(EXIT_FAILURE);
}

void	error_map_size(t_map *map)
{
	write(1, "Error: Map is not rectangular\n", 30);
	ft_exit_free(map);
}

void	error_wall(t_map *map)
{
	write(1, "Error: Map has insufficient walls\n", 34);
	ft_exit_free(map);
}

void	error_map_elements(t_map *map)
{
	write(1, "Error: Map has invalid elements\n", 33);
	ft_exit_free(map);
}
