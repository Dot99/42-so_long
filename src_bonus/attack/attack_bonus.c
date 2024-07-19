/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:58:08 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/19 15:40:15 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * @{
 * @file attack_bonus.c
 * @brief Handles the attacks
 */

#include "so_long_bonus.h"

/**
 * @brief Attack above
 * 
 * @param game Struct of the game
 */
void	attack_up(t_game *game)
{
	if (check_boss(game, 1) == 1)
	{
		if (check_attack(game, 1) == 1)
		{
			put_tile(game, "./textures/lightsaber_attack_up_floor.xpm",
				game->player.x * SIZE, (game->player.y - 1) * SIZE);
			put_tile(game, "./textures/attack_up.xpm",
				game->player.x * SIZE, game->player.y * SIZE);
			if (check_enemy(game, 1) == 1)
			{
				put_tile(game, "./textures/dead.xpm",
					game->player.x * SIZE, (game->player.y - 1) * SIZE);
				usleep(500000);
			}
			put_tile(game, "./textures/floor.xpm",
				game->player.x * SIZE, (game->player.y - 1) * SIZE);
			usleep(500000);
			put_tile(game, "./textures/mov_up1.xpm",
				game->player.x * SIZE, game->player.y * SIZE);
			game->enemies--;
			game->map[game->player.y - 1][game->player.x] = '0';
		}
	}
}

/**
 * @brief Attack right
 * 
 * @param game Struct of the game
 */
void	attack_right(t_game *game)
{
	if (check_boss(game, 2) == 1)
	{
		if (check_attack(game, 2) == 1)
		{
			put_tile(game, "./textures/lightsaber_attack_right_floor.xpm",
				(game->player.x + 1) * SIZE, game->player.y * SIZE);
			put_tile(game, "./textures/attack_right.xpm",
				game->player.x * SIZE, game->player.y * SIZE);
			if (check_enemy(game, 2) == 1)
			{
				put_tile(game, "./textures/dead.xpm",
					(game->player.x + 1) * SIZE, game->player.y * SIZE);
				usleep(500000);
			}
			put_tile(game, "./textures/floor.xpm",
				(game->player.x + 1) * SIZE, game->player.y * SIZE);
			usleep(500000);
			put_tile(game, "./textures/mov_right1.xpm",
				game->player.x * SIZE, game->player.y * SIZE);
			game->enemies--;
			game->map[game->player.y][game->player.x + 1] = '0';
		}
	}
}

/**
 * @brief Attack below
 * 
 * @param game Struct of the game
 */
void	attack_down(t_game *game)
{
	if (check_boss(game, 3) == 1)
	{
		if (check_attack(game, 3) == 1)
		{
			put_tile(game, "./textures/lightsaber_attack_down_floor.xpm",
				game->player.x * SIZE, (game->player.y + 1) * SIZE);
			put_tile(game, "./textures/attack_down.xpm",
				game->player.x * SIZE, game->player.y * SIZE);
			if (check_enemy(game, 3) == 1)
			{
				put_tile(game, "./textures/dead.xpm", game->player.x * SIZE,
					(game->player.y + 1) * SIZE);
				usleep(500000);
			}
			put_tile(game, "./textures/floor.xpm",
				game->player.x * SIZE, (game->player.y + 1) * SIZE);
			usleep(500000);
			put_tile(game, "./textures/mov_do1.xpm",
				game->player.x * SIZE, game->player.y * SIZE);
			game->enemies--;
			game->map[game->player.y + 1][game->player.x] = '0';
		}
	}
}

/**
 * @brief Attack left
 * 
 * @param game Struct of the game
 */
void	attack_left(t_game *game)
{
	if (check_boss(game, 4) == 1)
	{
		if (check_attack(game, 4) == 1)
		{
			put_tile(game, "./textures/lightsaber_attack_left_floor.xpm",
				(game->player.x - 1) * SIZE, game->player.y * SIZE);
			put_tile(game, "./textures/attack_left.xpm",
				game->player.x * SIZE, game->player.y * SIZE);
			if (check_enemy(game, 4) == 1)
			{
				put_tile(game, "./textures/dead.xpm",
					(game->player.x - 1) * SIZE, game->player.y * SIZE);
				usleep(500000);
			}
			put_tile(game, "./textures/floor.xpm",
				(game->player.x - 1) * SIZE, game->player.y * SIZE);
			usleep(500000);
			put_tile(game, "./textures/mov_left1.xpm",
				game->player.x * SIZE, game->player.y * SIZE);
			game->enemies--;
			game->map[game->player.y][game->player.x - 1] = '0';
		}
	}
}

/// @brief Function to handle attack
/// @param keysym Key Pressed (Arrow Keys)
/// @param game Struct of the game
void	attack(int keysym, t_game *game)
{
	if (game->lightsaber == 2)
	{
		if (keysym == XK_Up)
			attack_up(game);
		else if (keysym == XK_Down)
			attack_down(game);
		else if (keysym == XK_Left)
			attack_left(game);
		else if (keysym == XK_Right)
			attack_right(game);
	}
}

/**@}*/