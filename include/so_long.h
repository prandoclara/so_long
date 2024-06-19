/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:44:29 by claprand          #+#    #+#             */
/*   Updated: 2024/06/18 17:03:53 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include "define.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_sl
{
	/********** MLX **********/
	void	*mlx_ptr;
	void	*win_ptr;

	/********** MAP **********/
	char	**map;
	int		nbline;
	int		width_map;
	int		height_map;
	int		nbplayer;
	int		nbexit;
	int		nbitem;

	/******** PLAYER ********/
	void	*player;
	int		y_player;
	int		x_player;
	int		mov;

	/********* IMG *********/
	void	*wall;
	void	*floor;
	void	*item;
	void	*exit;
	int		player_sprite;
	int		width_img;
	int		height_img;
} t_sl;

/********** UTILS.C **********/
int		is_ber_file(char *s);
int		is_directory(char *s);
void	freetab(char **tab, int size);
int 	ft_strlen_no_newline(const char *str);
int		is_valid_char(char c);

/********** MAP.C **********/
int		open_map(t_sl *sl, char *file);
int		read_map(t_sl *sl, int fd);
int		init_maptab(t_sl *sl, char *file);
int		is_valid_map(t_sl *sl);

/********** CHECK_MAP.C **********/
int		is_rectangle(t_sl *sl);
int		check_wall(t_sl *sl);
int		check_char(t_sl *sl);
int		check_map_params(t_sl *sl);
int 	params_not_valid(t_sl *sl);

/********** INIT_GAME.C **********/
int	init_mlx(t_sl *sl);
int	load_images(t_sl *sl);
int render_map(t_sl *sl);
void free_resources(t_sl *sl);
int key_hook(int keycode, t_sl *sl);
int exit_game(t_sl *sl);
int close_window(t_sl *sl);
void	player_mov(t_sl *sl, int new_y, int new_x, int player_mov);
int	victory(t_sl *sl);

int is_valid_path(t_sl *sl);
int	flood_fill(t_sl *sl, int x, int y, char **visited, int nbitem);
void print_map(char **map, int height, int width);

#endif