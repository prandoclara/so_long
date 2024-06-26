/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:47:35 by claprand          #+#    #+#             */
/*   Updated: 2024/06/21 15:49:13 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_map(t_sl *sl, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error\nCan't open file for reading.\n", 2), 1);
	if (read_map(sl, fd) == 1)
		return (1);
	return (0);
}

int	read_map(t_sl *sl, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (ft_putstr_fd(EMPTY_MAP, 2), 1);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		sl->nbline++;
	}
	free(line);
	close(fd);
	if (sl->nbline < 3)
		return (ft_putstr_fd(ERROR_MAP, 2), 1);
	return (0);
}

int	init_maptab(t_sl *sl, char *file)
{
	int	i;
	int	fd;

	i = 0;
	sl->map = malloc(sizeof(char *) * (sl->nbline + 1));
	if (!sl->map)
		return (freetab(sl->map, sl->height_map), 1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (freetab(sl->map, sl->height_map), 1);
	while (i < sl->nbline)
	{
		sl->map[i] = get_next_line(fd);
		if (!sl->map[i])
			return (freetab(sl->map, sl->height_map), close(fd), 1);
		i++;
	}
	sl->map[i] = NULL;
	close(fd);
	return (0);
}

int	check_map_size(t_sl *sl)
{
	if ((sl->width_map * 32) > WIDTH_MAP_MAX
		|| (sl->height_map * 32) > HEIGHT_MAP_MAX)
	{
		ft_putstr_fd(ERROR_TOO_BIG, 2);
		freetab(sl->map, sl->height_map);
		return (1);
	}
	return (0);
}

int	is_valid_map(t_sl *sl)
{
	if (is_rectangle(sl) == 1)
		return (1);
	if (check_map_size(sl) == 1)
		return (1);
	if (check_wall(sl) == 1)
		return (1);
	if (check_char(sl) == 1)
		return (1);
	if (check_map_params(sl) == 1)
		return (1);
	return (0);
}
