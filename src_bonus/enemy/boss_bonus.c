/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boss_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:59:11 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/19 15:40:41 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * @{
 * @file boss_bonus.c
 * @brief Boss related functions
 */

#include "so_long_bonus.h"

/**
 * @brief Checks if the player is on contact with the attacks of the boss
 * 
 * @param game Struct of the game
 * @param z X coord
 * @param w Y coord
 */
void	check_contact_boss(t_game *game, int z, int w)
{
	if (((game->player.y == w - 1
				|| game->player.y == w
				|| game->player.y == w + 1)
			&& (game->player.x == z - 1
				|| game->player.x == z
				|| game->player.x == z + 1))
		&& game->health > 0)
		lose(game);
}

/**
 * @brief Replace the tiles of the surrounding area of the boss to his attacks
 * 
 * @param game Struct of the game
 * @param x X Coord
 * @param y Y Coord
 * @param type Works as boolean to check what to put on tiles
 */
void	spawn_boss_stuff(t_game *game, int x, int y, int type)
{
	if (type == 2)
	{
		put_tile(game, "./textures/light.xpm", (x - 1) * SIZE, (y - 1) * SIZE);
		usleep(500000);
		put_tile(game, "./textures/light.xpm", x * SIZE, (y - 1) * SIZE);
		put_tile(game, "./textures/light.xpm", (x + 1) * SIZE, (y - 1) * SIZE);
		put_tile(game, "./textures/light.xpm", (x - 1) * SIZE, y * SIZE);
		put_tile(game, "./textures/light.xpm", (x + 1) * SIZE, y * SIZE);
		put_tile(game, "./textures/light.xpm", (x - 1) * SIZE, (y + 1) * SIZE);
		put_tile(game, "./textures/light.xpm", x * SIZE, (y + 1) * SIZE);
		put_tile(game, "./textures/light.xpm", (x + 1) * SIZE, (y + 1) * SIZE);
	}
	else
	{
		put_tile(game, "./textures/floor.xpm", (x - 1) * SIZE, (y - 1) * SIZE);
		usleep(1000000);
		put_tile(game, "./textures/floor.xpm", x * SIZE, (y - 1) * SIZE);
		put_tile(game, "./textures/floor.xpm", (x + 1) * SIZE, (y - 1) * SIZE);
		put_tile(game, "./textures/floor.xpm", (x - 1) * SIZE, y * SIZE);
		put_tile(game, "./textures/floor.xpm", (x + 1) * SIZE, y * SIZE);
		put_tile(game, "./textures/floor.xpm", (x - 1) * SIZE, (y + 1) * SIZE);
		put_tile(game, "./textures/floor.xpm", x * SIZE, (y + 1) * SIZE);
		put_tile(game, "./textures/floor.xpm", (x + 1) * SIZE, (y + 1) * SIZE);
	}
}

/**
 * @brief Main Loop for boss
 * 
 * @param game 
 */
int	boss_loop(t_game *game)
{
	int	x;
	int	y;

	x = game->exit.x;
	y = game->exit.y;
	if (game->movement >= 4 && game->health > 0)
	{
		spawn_boss_stuff(game, x, y, 2);
		check_contact_boss(game, x, y);
		spawn_boss_stuff(game, x, y, 1);
		game->movement = 0;
	}
	return (0);
}

/**
 * @brief Spawns the boss
 * 
 * @param game Struct of the game
 * @param x X Coord
 * @param y Y Coord
 */
void	spawn_boss(t_game *game, int x, int y)
{
	game->spawn = 1;
	put_tile(game, "./textures/boss.xpm", x * SIZE, y * SIZE);
	spawn_boss_stuff(game, x, y, 2);
	spawn_boss_stuff(game, x, y, 1);
	put_health(game, game->health);
	mlx_loop_hook(game->mlx_ptr, boss_loop, game);
}

/// @brief Checks if the boss can spawn
/// @param game Struct of the game
void	check_boss_start(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	if (game->collected == game->collectibles
		&& game->spawn == 0
		&& game->enemies == 0)
	{
		x = game->exit.x;
		y = game->exit.y;
	}
	if (game->spawn == 1)
		game->movement++;
	if (!(x == -1) && !(y == -1))
		spawn_boss(game, x, y);
}

/**@}*/