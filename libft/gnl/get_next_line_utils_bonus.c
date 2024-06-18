/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:06:31 by claprand          #+#    #+#             */
/*   Updated: 2024/06/18 10:14:22 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_str_join_gnl(char *s1, char *s2)
{
	char	*new_str;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	free (s1);
	return (new_str);
}

char	*ft_strchr(char *s, int c)
{
	int				i;
	unsigned char	ch;

	i = 0;
	ch = c;
	if (!s)
		return (0);
	if (ch == '\0')
	{
		i = ft_strlen((char *)s);
		return ((char *)s + i++);
	}
	while ((char)s[i])
	{
		if ((char)s[i] == ch)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
