/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:57:37 by claprand          #+#    #+#             */
/*   Updated: 2024/06/14 16:53:41 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangle(t_sl *sl)
{	
	int	i;

	i = 0;
	sl->height_map = sl->nbline;
	sl->width_map = ft_strlen_no_newline(sl->map[0]);
	while (sl->map[i])
	{
		if (ft_strlen_no_newline(sl->map[i]) != sl->width_map)
		{
			ft_putstr_fd(ERROR_SIZE_MAP, 2);
			return (freetab(sl->map), 1);
		}
		i++;
	}
	return (0);
}

int	check_wall(t_sl *sl)
{
	int	i;

	i = 0;
	while (i < sl->width_map)
	{
		if (sl->map[0][i] != '1' || sl->map[sl->nbline - 1][i] != '1')
			return (ft_putstr_fd(ERROR_WALL, 2), freetab(sl->map), 1);
		i++;
	}
	i = 0;
	while (i < sl->height_map)
	{
		if (sl->map[i][0] != '1' || sl->map[i][sl->width_map - 1] != '1')
			return (ft_putstr_fd(ERROR_WALL, 2), freetab(sl->map), 1);
		i++;
	}
	return (0);
}

int	check_char(t_sl *sl)
{
	int	i;
	int	j;

	i = -1;
	while (++i < sl->height_map)
	{
		j = -1;
		while (++j < sl->width_map)
		{
			if (!is_valid_char(sl->map[i][j]))
				return (ft_putstr_fd("Error\n", 2), freetab(sl->map), 1);
		}
	}
	return (0);
}

int	check_map_params(t_sl *sl)
{
	int	y;
	int	x;

	y = -1;
	while (sl->map[++y])
	{
		x = -1;
		while (sl->map[y][++x])
		{
			if (sl->map[y][x] == 'P')
			{
				sl->nbplayer++;
				sl->player.x = x;
				sl->player.y = y;
			}	
			if (sl->map[y][x] == 'E')
				sl->nbexit++;
			if (sl->map[y][x] == 'C')
				sl->nbitem++;
		}
	}
	if ((params_not_valid(sl)) == 1)
		return (1);
	return (0);
}

int params_not_valid(t_sl *sl)
{	
	if (sl->nbplayer > 1)
		return (ft_putstr_fd(ERROR_PLAYER, 2), freetab(sl->map), 1);
	if (sl->nbplayer == 0)
		return (ft_putstr_fd(NO_PLAYER, 2), freetab(sl->map), 1);
	if (sl->nbexit > 1)
		return (ft_putstr_fd(ERROR_EXIT, 2), freetab(sl->map), 1);
	if (sl->nbexit == 0)
		return (ft_putstr_fd(NO_EXIT, 2), freetab(sl->map), 1);
	if (sl->nbitem < 1)
		return (ft_putstr_fd(ERROR_ITEM, 2), freetab(sl->map), 1);
	return (0);
}
