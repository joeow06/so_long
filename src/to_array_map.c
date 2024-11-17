/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_array_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeow <joeow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:57:46 by jow               #+#    #+#             */
/*   Updated: 2024/11/16 15:40:13 by joeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	set_counters(t_map *map)
{
	int	i;

	i = 0;
	while (map->array[i])
		i++;
	map->y = i;
	i = 0;
	while (map->array[0][i])
		i++;
	map->x = i;
}

int	map_to_array(t_map *map)
{
	int		n;
	int		fd;
	char	*temp_map;

	temp_map = ft_calloc(BUFF_SIZE + 1, sizeof(char));
	if (!temp_map)
		ft_exit_free(map);
	fd = open(map->filename, O_RDONLY);
	if (fd < 0)
		error_map_exit(2);
	n = read(fd, temp_map, BUFF_SIZE);
	if (n == -1 || n == 0)
		error_map_exit(3);
	map->array = ft_split(temp_map, '\n');
	map->copy = ft_split(temp_map, '\n');
	if (!map->array || !map->copy)
	{
		free(temp_map);
		ft_exit_free(map);
	}
	free(temp_map);
	set_counters(map);
	close(fd);
	return (0);
}
