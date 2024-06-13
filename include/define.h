/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:47:07 by claprand          #+#    #+#             */
/*   Updated: 2024/06/13 16:40:11 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/********** MESSAGES D'ERREURS **********/
# define ERROR_FORMAT "Error\nCan't open file. The format is not supported.\n"
# define ERROR_NB_FILES "Error\nCan't open multiples files!\n"
# define ERROR_MISSING_FILE "Error\nYou must run ./so_long with a .ber file!\n"
# define ERROR_DIRECTORY "Error\nThe file you passed as a parameter is a directory.\n"
# define ERROR_MAP "Error\nMap is too small.\n"
# define ERROR_SIZE_MAP "Error\nThe map is not rectangle.\n"
# define ERROR_WALL "Error\nThe map is not surrounded by wall.\n"
# define EMPTY_MAP "Error\nThe map is empty.\n"
# define ERROR_PLAYER "Error\nNumber of players not allowed.\n" 
# define ERROR_EXIT "Error\nNumber of exits not allowed.\n"

#endif