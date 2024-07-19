/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boss_health_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:29:29 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/19 15:40:45 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * @{
 * @file boss_health_bonus.c
 * @brief  Handles boss health
 */

#include "so_long_bonus.h"

/// @brief Changes a tile based on boss health
/// @param game Struct of the game
/// @param health Boss Health
void	put_health(t_game *game, int health)
{
	if (health == 3)
		put_tile(game, "./textures/health.xpm", 0 * SIZE, 0 * SIZE);
	else if (health == 2)
		put_tile(game, "./textures/health2.xpm", 0 * SIZE, 0 * SIZE);
	else if (health == 1)
		put_tile(game, "./textures/health3.xpm", 0 * SIZE, 0 * SIZE);
	else if (health == 0)
		put_tile(game, "./textures/health4.xpm", 0 * SIZE, 0 * SIZE);
}

/// @brief Handles boss health
/// @param game Struct of the game
/// @param n Direction of player
void	boss_damage(t_game *game, int n)
{
	boss_anim(game, n);
	game->health--;
	put_health(game, game->health);
	usleep(500000);
	if (game->health == 0)
	{
		game->spawn = 2;
		put_tile(game, "./textures/corner_top_left.xpm", 0 * SIZE, 0 * SIZE);
		put_tile(game, "./textures/exit.xpm",
			game->exit.x * SIZE, game->exit.y * SIZE);
	}
}

/**@}*/