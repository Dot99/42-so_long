/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:33:48 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/19 15:41:14 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * @{
 * @file movement_bonus.c
 * @brief Movements and win checker + movement animations
 */

#include "so_long_bonus.h"

/**
 * @brief Win Checker
 * @details Besides checking if the player has won, 
 * also allows the player to collect the lightsaber and
 * check if the boss can spawn
 * @param game Struct of the game
 */
void	check_win(t_game *game)
{
	if (game->map[game->player.y][game->player.x] == 'L')
	{
		game->lightsaber++;
		lightsaber(game);
	}
	if (game->map[game->player.y][game->player.x] == 'C'
	|| game->map[game->player.y][game->player.x] == 'L')
	{
		game->collected++;
		game->map[game->player.y][game->player.x] = '0';
		check_boss_start(game);
	}
	if (game->map[game->player.y][game->player.x] == 'E'
		&& game->collected != game->collectibles)
		return ;
	if (game->map[game->player.y][game->player.x] == 'E'
		&& game->collected == game->collectibles
		&& game->spawn == 2)
	{
		ft_printf("\nThere is only the force!\n");
		ft_printf("-------You win-------\n");
		ft_exit(game);
	}
}

/// @brief Movement up
/// @param game Struct of the game
void	move_up(t_game *game)
{
	int	n_pos;
	int	p_pos;

	p_pos = game->player.y;
	n_pos = game->player.y - 1;
	put_tile(game, "./textures/floor.xpm", game->player.x * SIZE, p_pos
		* SIZE);
	put_tile(game, "./textures/mov_up1.xpm",
		game->player.x * SIZE, n_pos * SIZE + ((SIZE / 3) * 2));
	put_tile(game, "./textures/floor.xpm", game->player.x * SIZE, p_pos
		* SIZE);
	check_lose(game, 1);
	usleep(75000);
	put_tile(game, "./textures/mov_up2.xpm", game->player.x * SIZE, n_pos * SIZE
		+ ((SIZE / 3)));
	put_tile(game, "./textures/floor.xpm", game->player.x * SIZE, p_pos
		* SIZE);
	usleep(75000);
	put_tile(game, "./textures/mov_up1.xpm",
		game->player.x * SIZE, n_pos * SIZE);
	put_tile(game, "./textures/floor.xpm", game->player.x * SIZE, p_pos
		* SIZE);
	game->player.y = n_pos;
	check_boss_start(game);
	check_win(game);
}

/// @brief Movement down
/// @param game Struct of the game
void	move_down(t_game *game)
{
	int	n_pos;
	int	p_pos;

	p_pos = game->player.y;
	n_pos = game->player.y + 1;
	put_tile(game, "./textures/floor.xpm", game->player.x * SIZE, p_pos
		* SIZE);
	put_tile(game, "./textures/mov_do1.xpm",
		game->player.x * SIZE, n_pos * SIZE - ((SIZE / 3) * 2));
	put_tile(game, "./textures/floor.xpm", game->player.x * SIZE, p_pos
		* SIZE);
	check_lose(game, 3);
	usleep(50000);
	put_tile(game, "./textures/mov_do2.xpm", game->player.x * SIZE, n_pos * SIZE
		- ((SIZE / 3)));
	put_tile(game, "./textures/floor.xpm", game->player.x * SIZE, p_pos
		* SIZE);
	usleep(50000);
	put_tile(game, "./textures/player.xpm",
		game->player.x * SIZE, n_pos * SIZE);
	put_tile(game, "./textures/floor.xpm", game->player.x * SIZE, p_pos
		* SIZE);
	game->player.y = n_pos;
	check_boss_start(game);
	check_win(game);
}

/// @brief Movement left
/// @param game Struct of the game
void	move_left(t_game *game)
{
	int	n_pos;
	int	p_pos;

	p_pos = game->player.x;
	n_pos = game->player.x - 1;
	put_tile(game, "./textures/floor.xpm", p_pos * SIZE, game->player.y
		* SIZE);
	put_tile(game, "./textures/mov_left1.xpm", n_pos * SIZE + ((SIZE / 3) * 2),
		game->player.y * SIZE);
	put_tile(game, "./textures/floor.xpm", p_pos * SIZE, game->player.y * SIZE);
	check_lose(game, 4);
	usleep(50000);
	put_tile(game, "./textures/mov_left2.xpm", n_pos * SIZE + ((SIZE / 3)),
		game->player.y * SIZE);
	put_tile(game, "./textures/floor.xpm", p_pos * SIZE, game->player.y * SIZE);
	usleep(50000);
	put_tile(game, "./textures/mov_left1.xpm",
		n_pos * SIZE, game->player.y * SIZE);
	put_tile(game, "./textures/floor.xpm", p_pos * SIZE, game->player.y * SIZE);
	game->player.x = n_pos;
	check_boss_start(game);
	check_win(game);
}

/// @brief Movement right
/// @param game Struct of the game
void	move_right(t_game *game)
{
	int	n_pos;
	int	p_pos;

	p_pos = game->player.x;
	n_pos = game->player.x + 1;
	put_tile(game, "./textures/floor.xpm", p_pos * SIZE, game->player.y
		* SIZE);
	put_tile(game, "./textures/mov_right1.xpm", n_pos * SIZE - ((SIZE / 3) * 2),
		game->player.y * SIZE);
	put_tile(game, "./textures/floor.xpm", p_pos * SIZE, game->player.y * SIZE);
	check_lose(game, 2);
	usleep(50000);
	put_tile(game, "./textures/mov_right2.xpm", n_pos * SIZE - ((SIZE / 3)),
		game->player.y * SIZE);
	put_tile(game, "./textures/floor.xpm", p_pos * SIZE, game->player.y * SIZE);
	usleep(50000);
	put_tile(game, "./textures/mov_right1.xpm",
		n_pos * SIZE, game->player.y * SIZE);
	put_tile(game, "./textures/floor.xpm", p_pos * SIZE, game->player.y * SIZE);
	game->player.x = n_pos;
	check_boss_start(game);
	check_win(game);
}

/**@}*/