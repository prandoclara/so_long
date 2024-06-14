/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:44:29 by claprand          #+#    #+#             */
/*   Updated: 2024/06/14 16:41:35 by claprand         ###   ########.fr       */
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

typedef struct s_img
{
	void * xpm_ptr;
	int type;
	int x;
	int y;
} t_img;

typedef struct s_position
{
	int	x;
	int	y;
} t_position;

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
	t_position 	player;
	t_img		wall;
	t_img		floor;
	t_img		item;
	t_img		exit;
	t_img		player_front;
	t_img		player_left;
	t_img		player_right;
	t_img		player_back;
	
} t_sl;

/********** UTILS.C **********/
int		is_ber_file(char *s);
int		is_directory(char *s);
void	freetab(char **tab);
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
int	init_sprites(t_sl *sl);
int new_sprite(void *mlx, char *path, int type, t_img *img);

#endif