/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:55:07 by claprand          #+#    #+#             */
/*   Updated: 2024/06/18 11:19:08 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_mlx(t_sl *sl)
{
	sl->mlx_ptr = mlx_init();
	if (!sl->mlx_ptr)
	{
		ft_putstr_fd(ERROR_MLXPTR, 2);
		return (1);
	}
	sl->win_ptr = mlx_new_window(sl->mlx_ptr, sl->width_map * IMG_WIDTH, sl->height_map * IMG_HEIGHT, "so_long");
	if (!sl->win_ptr)
	{
		ft_putstr_fd(ERROR_WINPTR, 2);
       	mlx_destroy_window(sl->mlx_ptr, sl->win_ptr);
     	mlx_destroy_display(sl->mlx_ptr);
    	free(sl->mlx_ptr);
		return (1);
	}
	return (0);
}

int	load_images(t_sl *sl)
{
	sl->wall = mlx_xpm_file_to_image(sl->mlx_ptr, WALL_XPM, &sl->width_img, &sl->height_img);
	if (!sl->wall)
		return (free_resources(sl), 1);
	sl->floor = mlx_xpm_file_to_image(sl->mlx_ptr, FLOOR_XPM, &sl->width_img, &sl->height_img);
	if (!sl->floor)
		return (free_resources(sl), 1);
	sl->exit = mlx_xpm_file_to_image(sl->mlx_ptr, EXIT_XPM, &sl->width_img, &sl->height_img);
	if (!sl->exit)
		return (free_resources(sl), 1);
	sl->item = mlx_xpm_file_to_image(sl->mlx_ptr, ITEM_XPM, &sl->width_img, &sl->height_img);
	if (!sl->item)
		return (free_resources(sl), 1);
	sl->player = mlx_xpm_file_to_image(sl->mlx_ptr, PLAYER_FRONT_XPM, &sl->width_img, &sl->height_img);
	if (!sl->player)
		return (free_resources(sl), 1);
	return (0);
}

int render_map(t_sl *sl)
{
	int y;
	int x;

	y = 0;
	while(y < sl->height_map)
	{
		x = 0;
		while (x < sl->width_map)
		{
			if (sl->map[y][x] == '1')
				mlx_put_image_to_window(sl->mlx_ptr, sl->win_ptr, sl->wall, x * 32, y *32);
			if (sl->map[y][x] == '0')
				mlx_put_image_to_window(sl->mlx_ptr, sl->win_ptr, sl->floor, x * 32, y *32);
			if (sl->map[y][x] == 'P')
				mlx_put_image_to_window(sl->mlx_ptr, sl->win_ptr, sl->player, x * 32, y *32);
			if (sl->map[y][x] == 'C')
				mlx_put_image_to_window(sl->mlx_ptr, sl->win_ptr, sl->item, x * 32, y *32);
			if (sl->map[y][x] == 'E')
				mlx_put_image_to_window(sl->mlx_ptr, sl->win_ptr, sl->exit, x * 32, y *32);
			x++;
		}	
		y++;
	}
	return (0);
}

int key_hook(int keysym, t_sl *sl)
{
    if (keysym == XK_Escape || keysym == XK_q)
		exit_game(sl);
	if (keysym == XK_w || keysym == XK_Up)
		player_mov(sl, sl->y_player - 1, sl->x_player, BACK);
	if (keysym == XK_a || keysym == XK_Left)
		player_mov(sl, sl->y_player, sl->x_player - 1, LEFT);
	if (keysym == XK_d || keysym == XK_Right)
		player_mov(sl, sl->y_player, sl->x_player + 1, RIGHT);
	if (keysym == XK_s || keysym == XK_Down)
		player_mov(sl, sl->y_player + 1, sl->x_player, FRONT);

    return (0);
}

void	player_mov(t_sl *sl, int new_y, int new_x, int player_mov)
{
	int last_x;
	int last_y;

	sl->player_sprite = player_mov;
	last_x = sl->x_player;
	last_y = sl->y_player;
	if (sl->map[new_y][new_x] == EXIT && sl->nbitem == 0)
		victory(sl);
	else if ((sl->map[new_y][new_x] == ESP) || (sl->map[new_y][new_x] == ITEM))
	{
		if (sl->map[new_y][new_x] == ITEM)
			sl->nbitem--;
		sl->map[last_y][last_x] = ESP;
		sl->x_player = new_x;
		sl->y_player = new_y;
		sl->map[new_y][new_x] = PLAYER;
		sl->mov++;
		render_map(sl);
	}
}
