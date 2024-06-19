/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:36:28 by claprand          #+#    #+#             */
/*   Updated: 2024/06/19 15:48:46 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill(t_sl *sl, int x, int y, char **visited)
{
	if (x < 0 || x >= sl->height_map || y < 0 || y >= sl->width_map)
		return (1);
	if (sl->map[x][y] == WALL || visited[x][y] == 'V')
		return (1);
	if (sl->map[x][y] == EXIT)
		return (0);
	visited[x][y] = 'V';
	if (flood_fill(sl, x + 1, y, visited) == 0)
		return (0);
	if (flood_fill(sl, x - 1, y, visited) == 0)
		return (0);
	if (flood_fill(sl, x, y + 1, visited) == 0)
		return (0);
	if (flood_fill(sl, x, y - 1, visited) == 0)
		return (0);
	return (1);
}

int	is_valid_path(t_sl *sl)
{
	char	**visited;
	int		i;
	int		j;
	int		res;

	visited = (char **)malloc(sl->height_map * sizeof(char *));
	if (!visited)
		return (1);
	i = -1;
	while (++i < sl->height_map)
	{
		visited[i] = (char *)malloc(sl->width_map * sizeof(char));
		if (!visited[i])
		{
			freetab(visited, i);
			return (1);
		}
		j = -1;
		while (++j < sl->width_map)
			visited[i][j] = sl->map[i][j];
	}
	res = flood_fill(sl, sl->x_player, sl->y_player, visited);
	freetab(visited, i);
	return (res);
}
