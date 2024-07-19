/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:54:25 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/19 15:40:57 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * @{
 * @file check_map1_bonus.c
 * @brief Verifications of the map 1 + new characters
 */

#include "so_long_bonus.h"

/**
 * @brief Counts if the map has the necessary things to work
 * @param game Struct of the game
 */
void	count_map_assets(t_game *game)
{
	int	x;
	int	y;
	int	player;
	int	exit;

	player = 0;
	exit = 0;
	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			if (game->map[y][x] == 'P')
				player++;
			else if (game->map[y][x] == 'E')
				exit++;
		}
	}
	if (player != 1 || exit != 1)
		dead(7, game);
}

/// @brief Checks the content of the map
/// @param game Struct of the game
void	check_map_content(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				game->player.x = x;
				game->player.y = y;
			}
			else if (game->map[y][x] == 'E')
			{
				game->exit.x = x;
				game->exit.y = y;
			}
			else if (game->map[y][x] == 'C' || game->map[y][x] == 'L')
				game->collectibles++;
			else if (game->map[y][x] == 'X')
				game->enemies++;
		}
	}
}

/// @brief Checks the map size
/// @param game Struct of the game
void	check_map_size(t_game *game)
{
	int	y;

	y = -1;
	while (++y != game->height)
	{
		if ((game->height + game->width <= 7) || (game->height < 3
				|| game->width < 3))
			dead(4, game);
		if ((ft_n_strclen(game->map[y]) != game->width)
			&& (game->map[y] != NULL))
			dead(5, game);
	}
}

/// @brief Checks the borders of the game
/// @param game Struct of the game
void	check_borders(t_game *game)
{
	t_point	coords;

	coords.y = -1;
	while (++coords.y < game->height)
	{
		if (coords.y == 0 || coords.y == game->height - 1)
		{
			coords.x = -1;
			while (++coords.x < game->width)
			{
				if (game->map[coords.y][coords.x] != '1')
					dead(5, game);
			}
		}
		else if (game->map[coords.y][0] != '1'
			|| game->map[coords.y][game->width - 1] != '1')
			dead(5, game);
	}
}

/// @brief Validates the map
/// @param game Struct of the game
void	map_validation(t_game *game)
{
	check_map_size(game);
	check_borders(game);
	count_map_assets(game);
	check_map_content(game);
	check_map_assets(game);
	check_valid_path(game);
	check_collectibles(game);
}

/**@}*/