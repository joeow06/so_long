/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeow <joeow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:42:48 by jow               #+#    #+#             */
/*   Updated: 2024/11/14 17:20:09 by joeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_exit_free(t_map *map)
{
	int	i;

	i = 0;
	if (map->array)
	{
		while (map->array[i])
		{
			free(map->array[i]);
			i++;
		}
		free(map->array);
	}
	if (map->copy)
	{
		i = 0;
		while (map->copy[i])
		{
			free(map->copy[i]);
			i++;
		}
		free(map->copy);
	}
	exit(EXIT_FAILURE);
}

int	ft_free_array(char **a, int i)
{
	while (i > 0)
		free(a[--i]);
	free(a);
	return (0);
}

void	ft_won(t_map *map)
{
	int	i;

	i = 0;
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
