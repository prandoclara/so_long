/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:57:37 by claprand          #+#    #+#             */
/*   Updated: 2024/06/13 16:46:47 by claprand         ###   ########.fr       */
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

int	check_p_e(t_sl *sl)
{
	int	nbplayer;
	int	nbexit;
	int	i;
	int	j;

	nbplayer = 0;
	nbexit = 0;
	i = -1;
	while (sl->map[++i])
	{
		j = -1;
		while (sl->map[i][++j])
		{
			if (sl->map[i][j] == 'P')
				nbplayer++;
			if (sl->map[i][j] == 'E')
				nbexit++;
		}
	}
	if (nbplayer > 1 || nbplayer == 0)
		return (ft_putstr_fd(ERROR_PLAYER, 2), freetab(sl->map), 1);
	if (nbexit > 1 || nbexit == 0)
		return (ft_putstr_fd(ERROR_EXIT, 2), freetab(sl->map), 1);
	return (0);
}

/*
1 = wall
0 = espaces vides
E = exit
C = item to collect
P = player

OK si ma map est rectangle 
OK si ma map ne contient pas de lignes vides
OK la premiere ligne ne doit etre que des 1
OK la derniere ligne ne doit etre que des 1
OK le premier char de chaque ligne doit etre un 1
OK le dernier char de chaque ligne doit etre un 1

a partir de la ligne 2 jusqu'a l'avant derniere ligne je peux trouver : 
plusieurs 0, plusieurs C, un seul P, un seul E

si le P a deja ete trouve precedemment, je dois quitter
si le E a deja ete trouve precedemment, je dois quitter

verifier s'il y a un chemin valide 
retourner "Error\n" suivi d’un message d’erreur explicite de votre choix
*/