/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:55:07 by claprand          #+#    #+#             */
/*   Updated: 2024/06/14 16:48:02 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_mlx(t_sl *sl)
{
	sl->mlx_ptr = mlx_init();
	if (!sl->mlx_ptr)
	{
		free(sl->mlx_ptr);
		ft_putstr_fd(ERROR_MLXPTR, 2);
		return (1);
	}
	sl->win_ptr = mlx_new_window(sl->mlx_ptr, sl->width_map * IMG_WIDTH, sl->height_map * IMG_HEIGHT, "so_long");
	if (!sl->win_ptr)
	{
		free(sl->win_ptr);
		free(sl->mlx_ptr);
		ft_putstr_fd(ERROR_WINPTR, 2);
		return (1);
	}
	return (0);
}

int init_sprites(t_sl *sl)
{
	if (new_sprite(sl->mlx_ptr, WALL_XPM, WALL, &sl->wall))
		return (1);
	if (new_sprite(sl->mlx_ptr, FLOOR_XPM, ESP, &sl->floor))
		return (1);
	if (new_sprite(sl->mlx_ptr, ITEM_XPM, ITEM, &sl->item))
		return (1);
	if (new_sprite(sl->mlx_ptr, PLAYER_FRONT_XPM, PLAYER, &sl->player_front))
		return (1);
	if (new_sprite(sl->mlx_ptr, PLAYER_LEFT_XPM, PLAYER, &sl->player_left))
		return (1);
	if (new_sprite(sl->mlx_ptr, PLAYER_RIGHT_XPM, PLAYER, &sl->player_right))
		return (1);
	if (new_sprite(sl->mlx_ptr, PLAYER_BACK_XPM, PLAYER, &sl->player_back))
		return (1);
	if (new_sprite(sl->mlx_ptr, EXIT_XPM, EXIT, &sl->exit))
		return (1);
	return (0);
}

int new_sprite(void *mlx, char *path, int type, t_img *img)
{
	img->xpm_ptr = mlx_xpm_file_to_image(mlx, path, &img->x, &img->y);
	if (!img->xpm_ptr)
	{
		ft_putstr_fd("Couldn't find a sprite. Does it exist?\n", 2);
		mlx_destroy_image(mlx, img->xpm_ptr);
		free(mlx);
		return (1);
	}
	img->type = type;
	return (0);
}




