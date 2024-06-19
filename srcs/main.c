/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:50:51 by claprand          #+#    #+#             */
/*   Updated: 2024/06/19 16:42:19 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_sl *sl, char *av)
{
	if (is_directory(av) == 0)
		return (ft_putstr_fd(ERROR_DIRECTORY, 2), 1);
	if (open_map(sl, av) == 1)
		return (1);
	if (init_maptab(sl, av) == 1)
		return (1);
	if (is_valid_map(sl) == 1)
		return (1);
	if (is_valid_path(sl) == 1)
	{
		ft_putstr_fd(ERROR_NO_PATH, 2);
		freetab(sl->map, sl->height_map);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{	
	t_sl	sl;

	ft_memset(&sl, 0, sizeof(t_sl));
	if (ac == 2 && !(is_ber_file(av[1])))
		ft_putstr_fd(ERROR_FORMAT, 2);
	else if (ac > 2)
		ft_putstr_fd(ERROR_NB_FILES, 2);
	else if (ac < 2)
		ft_putstr_fd(ERROR_MISSING_FILE, 2);
	else if (ac == 2 && is_ber_file(av[1]))
	{
		if (check_map(&sl, av[1]) == 1)
			return (1);
		if (init_mlx(&sl) == 1)
			return (1);
		if (load_images(&sl) == 1)
			return (1);
		render_map(&sl, -1, -1);
	}
	mlx_hook(sl.win_ptr, KeyPress, KeyPressMask, key_hook, &sl);
	mlx_hook(sl.win_ptr, DestroyNotify, ButtonPressMask, exit_game, &sl);
	mlx_hook(sl.win_ptr, Expose, ExposureMask, render_map, &sl);
	mlx_loop(sl.mlx_ptr);
	free_resources(&sl);
	return (0);
}
