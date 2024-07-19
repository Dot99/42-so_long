/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_checker_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:21:24 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/19 15:40:32 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * @{
 * @file attack_checker_bonus.c
 * @brief  Checks the attack and enemies position
 */

#include "so_long_bonus.h"

/// @brief Checks if the player can attack in n direction
/// @param game Struct of the game
/// @param n Direction of the attack
/// @return 1 if not allowed otherwise 0
int	check_attack(t_game *game, int n)
{
	if (n == 1)
		if (game->map[game->player.y - 1][game->player.x] != '1'
		&& game->map[game->player.y - 1][game->player.x] != 'C'
		&& game->map[game->player.y - 1][game->player.x] != 'E')
			return (1);
	if (n == 4)
		if (game->map[game->player.y][game->player.x - 1] != '1'
		&& game->map[game->player.y][game->player.x - 1] != 'C'
		&& game->map[game->player.y][game->player.x - 1] != 'E')
			return (1);
	if (n == 3)
		if (game->map[game->player.y + 1][game->player.x] != '1'
		&& game->map[game->player.y + 1][game->player.x] != 'C'
		&& game->map[game->player.y + 1][game->player.x] != 'E')
			return (1);
	if (n == 2)
		if (game->map[game->player.y][game->player.x + 1] != 'C'
		&& game->map[game->player.y][game->player.x + 1] != '1'
		&& game->map[game->player.y][game->player.x + 1] != 'E')
			return (1);
	return (0);
}

/// @brief Checks if there is an enemy based on direction
/// @param game Struct of the game
/// @param n Direction
/// @return 1 if found enemy otherwise 0
int	check_enemy(t_game *game, int n)
{
	if (n == 1)
	{
		if (game->map[game->player.y - 1][game->player.x] == 'X')
			return (1);
	}
	if (n == 4)
	{
		if (game->map[game->player.y][game->player.x - 1] == 'X')
			return (1);
	}
	if (n == 3)
	{
		if (game->map[game->player.y + 1][game->player.x] == 'X')
			return (1);
	}
	if (n == 2)
	{
		if (game->map[game->player.y][game->player.x + 1] == 'X')
			return (1);
	}
	return (0);
}

/**@}*/