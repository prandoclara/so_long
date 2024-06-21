/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:36:19 by claprand          #+#    #+#             */
/*   Updated: 2024/06/21 14:47:13 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_resources(t_sl *sl)
{
	if (sl->wall)
		mlx_destroy_image(sl->mlx_ptr, sl->wall);
	if (sl->floor)
		mlx_destroy_image(sl->mlx_ptr, sl->floor);
	if (sl->item)
		mlx_destroy_image(sl->mlx_ptr, sl->item);
	if (sl->exit)
		mlx_destroy_image(sl->mlx_ptr, sl->exit);
	if (sl->player)
		mlx_destroy_image(sl->mlx_ptr, sl->player);
	if (sl->win_ptr)
		mlx_destroy_window(sl->mlx_ptr, sl->win_ptr);
	if (sl->mlx_ptr)
	{
		mlx_destroy_display(sl->mlx_ptr);
		free(sl->mlx_ptr);
	}
	if (sl->map)
		freetab(sl->map, sl->height_map);
}

int	victory(t_sl *sl)
{
	ft_printf("\nNombre total de mouvements : %d\n\n", sl->mov);
	ft_printf("*****************\n");
	ft_printf("*   YOU WIN !   *\n");
	ft_printf("*****************\n");
	ft_printf("\n");
	exit_game(sl);
	return (0);
}

int	exit_game(t_sl *sl)
{
	free_resources(sl);
	exit(0);
	return (0);
}
