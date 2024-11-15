/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeow <joeow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:33:06 by jow               #+#    #+#             */
/*   Updated: 2024/11/16 02:33:52 by joeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"

# define BUFF_SIZE 10000
# define IMG_PXL 50
# define WND_NAME "so_long"
# define UP      XK_w
# define DOWN    XK_s
# define LEFT    XK_a
# define RIGHT   XK_d

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*collectible;
	void	*exit;
	void	*player;
}	t_img;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_map
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			*filename;
	char			**array;
	char			**copy;
	int				fd;
	int				x;
	int				y;
	int				e;
	int				c;
	int				p;
	int				moves;
	int				exit;
	int				e_check;
	int				c_check;
	t_player		player;
	t_img			img;
}	t_map;

void	map_checker(t_map *map);
int		map_to_array(t_map *map);
void	error_map_exit(int i);
void	error_map_size(t_map *map);
void	error_map_elements(t_map *map);
void	ft_exit_free(t_map *map);
void	ft_won(t_map *map);
void	error_wall(t_map *map);
void	check_valid_path(t_map *map);
void	scan_player(t_map *map);
void	move_on_paths(int x, int y, t_map *map);
int		ft_free_array(char **a, int i);
int		close_game(t_map *map);
void	convert_image(t_map *map);
void	map_printer(t_map *map);
void	print_movements(t_map *map);
void	move_up(t_map *map);
void	move_left(t_map *map);
void	move_right(t_map *map);
void	move_down(t_map *map);
void	render_map(t_map *map);

#endif
