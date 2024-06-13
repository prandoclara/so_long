/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:50:51 by claprand          #+#    #+#             */
/*   Updated: 2024/06/13 13:19:36 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		if (is_directory(av[1]) == 0)
			return (ft_putstr_fd(ERROR_DIRECTORY, 2), 1);
		if (open_map(&sl, av[1]) == 1)
			return (1);
		if (init_maptab(&sl, av[1]) == 1)
			return (1);
		if (is_valid_map(&sl) == 1)
			return (1);
	}
	freetab(sl.map);
	return (0);
}
