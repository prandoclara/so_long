/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:47:07 by claprand          #+#    #+#             */
/*   Updated: 2024/06/14 15:32:48 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H


# define IMG_HEIGHT			32
# define IMG_WIDTH			32

/********** MESSAGES D'ERREURS **********/
# define ERROR_FORMAT "Error\nCan't open file. The format is not supported.\n"
# define ERROR_NB_FILES "Error\nCan't open multiples files!\n"
# define ERROR_MISSING_FILE "Error\nYou must run ./so_long with a .ber file!\n"
# define ERROR_DIRECTORY "Error\nThe file you passed as a parameter is a directory.\n"
# define ERROR_MAP "Error\nMap is too small.\n"
# define ERROR_SIZE_MAP "Error\nThe map is not rectangle.\n"
# define ERROR_WALL "Error\nThe map is not surrounded by wall.\n"
# define EMPTY_MAP "Error\nThe map is empty.\n"
# define ERROR_PLAYER "Error\nYou can only play this game with one player.\n" 
# define NO_PLAYER "Error\nYou need one player to play.\n"
# define ERROR_EXIT "Error\nOnly one exit is allowed.\n"
# define NO_EXIT "Error\nThere is no exit."
# define ERROR_ITEM "Error\nYou need at least one item to collect in the map.\n"
# define ERROR_MLXPTR "Error\nCan't find mlx pointer.\n"
# define ERROR_WINPTR "Error\nCouldn't create the Window.\n"

# define WALL '1'
# define ESP '0'
# define EXIT 'E'
# define ITEM 'C'
# define PLAYER 'P'

# define WALL_XPM "./assets/wall.xpm"
# define FLOOR_XPM "./assets/floor.xpm"
# define ITEM_XPM "./assets/item.xpm"
# define PLAYER_FRONT_XPM "./assets/player.xpm"
# define PLAYER_LEFT_XPM "./assets/playerleft.xpm"
# define PLAYER_RIGHT_XPM "./assets/playerright.xpm"	
# define PLAYER_BACK_XPM "./assets/playerback.xpm"
# define EXIT_XPM "./assets/exit.xpm"

#endif