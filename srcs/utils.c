/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:55:53 by claprand          #+#    #+#             */
/*   Updated: 2024/06/14 14:23:26 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_ber_file(char *s)
{
	char	*str;

	str = ft_strrchr(s, '.');
	if (str)
		return (ft_strncmp(str, ".ber", 100) == 0);
	return (0);
}

int	is_directory(char *s)
{
	int	fd;

	fd = open(s, O_DIRECTORY);
	if (fd == -1)
		return (1);
	close (fd);
	return (0);
}

void	freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_strlen_no_newline(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

int	is_valid_char(char c)
{
	return (c == 'E' || c == 'C' || c == 'P' || c == '0' || c == '1');
}
