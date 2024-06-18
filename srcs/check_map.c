/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:57:37 by claprand          #+#    #+#             */
/*   Updated: 2024/06/18 16:59:11 by claprand         ###   ########.fr       */
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
			return (freetab(sl->map, sl->height_map), 1);
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
			return (ft_putstr_fd(ERROR_WALL, 2), freetab(sl->map, sl->height_map), 1);
		i++;
	}
	i = 0;
	while (i < sl->height_map)
	{
		if (sl->map[i][0] != '1' || sl->map[i][sl->width_map - 1] != '1')
			return (ft_putstr_fd(ERROR_WALL, 2), freetab(sl->map, sl->height_map), 1);
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
				return (ft_putstr_fd("Error\n", 2), freetab(sl->map, sl->height_map), 1);
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
				sl->x_player = x;
				sl->y_player = y;
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
		return (ft_putstr_fd(ERROR_PLAYER, 2), freetab(sl->map, sl->height_map), 1);
	if (sl->nbplayer == 0)
		return (ft_putstr_fd(NO_PLAYER, 2), freetab(sl->map, sl->height_map), 1);
	if (sl->nbexit > 1)
		return (ft_putstr_fd(ERROR_EXIT, 2), freetab(sl->map, sl->height_map), 1);
	if (sl->nbexit == 0)
		return (ft_putstr_fd(NO_EXIT, 2), freetab(sl->map, sl->height_map), 1);
	if (sl->nbitem <= 0)
		return (ft_putstr_fd(ERROR_ITEM, 2), freetab(sl->map, sl->height_map), 1);
	return (0);
}

int	flood_fill(t_sl *sl, int x, int y, char **visited, int nbitem)
{
	int i;

	i = 0;
	if (x < 0 || x >= sl->height_map || y < 0 || y >= sl->width_map)
		return (printf("ha\n"), 1);
	if (sl->map[x][y] == WALL || visited[x][y] == 'V')
		return (printf("heho\n"), 1);
	visited[x][y] = 'V';
	if (sl->map[x][y] == ITEM)
	{
		nbitem++;
	}
	if (sl->map[x][y] == EXIT && nbitem == sl->nbitem)
	{
		printf("la\n");
		return (0);
	}
	printf("%d\n", nbitem);
	if (!flood_fill(sl, x + 1, y, visited, nbitem))
		return (0);
	if (!flood_fill(sl, x - 1, y, visited, nbitem))
		return (0);
	if (!flood_fill(sl, x, y + 1, visited, nbitem))
		return (0);
	if (!flood_fill(sl, x, y - 1, visited, nbitem))
		return (0);
	return (printf("allo\n"), 1);
}

int is_valid_path(t_sl *sl)
{
	char **visited;
	int i;
	int j;
	int res;

	visited = (char **)malloc(sl->height_map * sizeof(char *));
	if (!visited)
		return (1);
	i = 0;
	while(i < sl->height_map)
	{
		visited[i] = (char *)malloc(sl->width_map * sizeof(char));
		if (!visited[i])
		{
			freetab(visited, i);
			return (1);
		}
		j = 0;
		while (j < sl->width_map)
		{
			visited[i][j] = sl->map[i][j];
			j++;
		}
		i++;
	}
	res = flood_fill(sl, sl->x_player, sl->y_player, visited, 0);
	printf("\n");
	print_map(visited, sl->height_map, sl->width_map);
	freetab(visited, i);
	return(res);
}

void print_map(char **map, int height, int width)
{
	int i, j;

	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}