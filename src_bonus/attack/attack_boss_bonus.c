/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_boss_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:55:57 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/19 15:40:27 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * @{
 * @file attack_boss_bonus.c
 * @brief Handles boss animation and damage to the player
 */

#include "so_long_bonus.h"

/// @brief Handles the boss damage to the player
/// @param game Struct of the game
/// @param n Direction of player
/// @return 1 if player is outside of boss range otherwise 0
int	check_boss(t_game *game, int n)
{
	if (game->spawn == 1
		&& game->enemies == 0
		&& game->collected == game->collectibles)
	{
		if (n == 1)
			if (game->map[game->player.y - 1][game->player.x] != 'E')
				return (1);
		if (n == 4)
			if (game->map[game->player.y][game->player.x - 1] != 'E')
				return (1);
		if (n == 3)
			if (game->map[game->player.y + 1][game->player.x] != 'E')
				return (1);
		if (n == 2)
			if (game->map[game->player.y][game->player.x + 1] != 'E')
				return (1);
		game->movement += 2;
		boss_damage(game, n);
	}
	else
		return (1);
	return (0);
}

/// @brief Handles the attack on the boss from his right
/// @param game Struct of the game
/// @param n Direction of player
void	boss_anim4(t_game *game)
{
	put_tile(game, "./textures/lightsaber_attack_left_floor.xpm",
		(game->player.x - 1) * SIZE, game->player.y * SIZE);
	put_tile(game, "./textures/attack_left.xpm",
		game->player.x * SIZE, game->player.y * SIZE);
	put_tile(game, "./textures/mov_left1.xpm",
		game->player.x * SIZE, game->player.y * SIZE);
	usleep(500000);
	put_tile(game, "./textures/boss_hit.xpm",
		(game->player.x - 1) * SIZE, game->player.y * SIZE);
	usleep(1000000);
	put_tile(game, "./textures/boss.xpm",
		(game->player.x - 1) * SIZE, game->player.y * SIZE);
}

/// @brief Handles the attack on the boss from above him
/// @param game Struct of the game
/// @param n Direction of player
void	boss_anim3(t_game *game, int n)
{
	if (n == 3)
	{
		put_tile(game, "./textures/lightsaber_attack_down_floor.xpm",
			game->player.x * SIZE, (game->player.y + 1) * SIZE);
		put_tile(game, "./textures/attack_down.xpm",
			game->player.x * SIZE, game->player.y * SIZE);
		put_tile(game, "./textures/mov_do1.xpm",
			game->player.x * SIZE, game->player.y * SIZE);
		usleep(500000);
		put_tile(game, "./textures/boss_hit.xpm",
			game->player.x * SIZE, (game->player.y + 1) * SIZE);
		usleep(1000000);
		put_tile(game, "./textures/boss.xpm",
			game->player.x * SIZE, (game->player.y + 1) * SIZE);
	}
	else
		boss_anim4(game);
}

/// @brief Handles the attack on the boss from his left
/// @param game Struct of the game
/// @param n Direction of player
void	boss_anim2(t_game *game, int n)
{
	if (n == 2)
	{
		put_tile(game, "./textures/lightsaber_attack_right_floor.xpm",
			(game->player.x + 1) * SIZE, game->player.y * SIZE);
		put_tile(game, "./textures/attack_right.xpm",
			game->player.x * SIZE, game->player.y * SIZE);
		put_tile(game, "./textures/mov_right1.xpm",
			game->player.x * SIZE, game->player.y * SIZE);
		put_tile(game, "./textures/boss_hit.xpm",
			(game->player.x + 1) * SIZE, game->player.y * SIZE);
		usleep(1000000);
		put_tile(game, "./textures/boss.xpm",
			(game->player.x + 1) * SIZE, game->player.y * SIZE);
		usleep(1000000);
	}
	else
		boss_anim3(game, n);
}

/// @brief Handles the attack on the boss from below him
/// @param game Struct of the game
/// @param n Direction of player
void	boss_anim(t_game *game, int n)
{
	if (n == 1)
	{
		put_tile(game, "./textures/lightsaber_attack_up_floor.xpm",
			game->player.x * SIZE, (game->player.y - 1) * SIZE);
		put_tile(game, "./textures/attack_up.xpm",
			game->player.x * SIZE, game->player.y * SIZE);
		put_tile(game, "./textures/mov_up1.xpm",
			game->player.x * SIZE, game->player.y * SIZE);
		usleep(500000);
		put_tile(game, "./textures/boss_hit.xpm",
			game->player.x * SIZE, (game->player.y - 1) * SIZE);
		put_tile(game, "./textures/boss.xpm",
			game->player.x * SIZE, (game->player.y - 1) * SIZE);
		usleep(500000);
	}
	else
		boss_anim2(game, n);
}

/**@}*/