/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightsaber_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:41:12 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/19 15:40:35 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * @{
 * @file lightsaber_bonus.c
 * @brief Weapon check
 */

#include "so_long_bonus.h"

/// @brief Detects if player collected the weapon and allows him to attack
/// @param game Struct of the game
void	lightsaber(t_game *game)
{
	int	p_pos;

	if (game->lightsaber == 1)
	{
		game->lightsaber++;
		p_pos = game->player.y;
		put_tile(game, "./textures/player.xpm",
			game->player.x * SIZE, p_pos * SIZE);
		usleep(50000);
		put_tile(game, "./textures/player_lightsaber.xpm",
			game->player.x * SIZE, p_pos * SIZE);
	}
}

/**@}*/