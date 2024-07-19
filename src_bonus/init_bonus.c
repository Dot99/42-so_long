/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:39:16 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/19 15:42:55 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * @{
 * @file init_bonus.c
 * @brief Initializes the struct
 */

#include "so_long_bonus.h"

/// @brief Initializes the contents of the struct
/// @param game Struct of the game
void	init_game(t_game *game)
{
	game->map = NULL;
	game->width = 0;
	game->height = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->exit.x = 0;
	game->exit.y = 0;
	game->collectibles = 0;
	game->gathered = 0;
	game->collected = 0;
	game->moves = 0;
	game->coords.x = -1;
	game->coords.y = -1;
	game->tile.x = 0;
	game->tile.y = 0;
	game->lightsaber = 0;
	game->enemies = 0;
	game->spawn = 0;
	game->health = 3;
	game->movement = 0;
}

/// @brief Initializes the content of the struct which MLX needs
/// @param game 
void	init_img(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = NULL;
	game->img.mlx_img = NULL;
	game->img.addr = NULL;
	game->img.bpp = 0;
	game->img.line_len = 0;
	game->img.endian = 0;
	game->tile.y = SIZE;
	game->tile.x = SIZE;
}

/// @brief Start the game
/// @param  void
/// @return Game Struct
t_game	*init(void)
{
	t_game	*game;

	game = malloc((1) * sizeof(t_game));
	if (!game)
		dead(6, game);
	init_game(game);
	init_img(game);
	return (game);
}

/**@}*/