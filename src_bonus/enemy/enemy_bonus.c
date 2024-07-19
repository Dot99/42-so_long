/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:01:35 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/19 15:40:47 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * @{
 * @file enemy_bonus.c
 * @brief Renders enemies anim and lose checks
 */

#include "so_long_bonus.h"

/// @brief Renders the "movement" of the enemies
/// @param game Struct of the game
/// @return 
int	render_anim(t_game *game)
{
	game->coords.y = -1;
	while (++game->coords.y < game->height)
	{
		game->coords.x = -1;
		while (++game->coords.x < game->width)
		{
			if (game->map[game->coords.y][game->coords.x] == 'X')
			{
				put_tile(game, "./textures/enemy1.xpm",
					game->coords.x * SIZE, game->coords.y * SIZE);
				put_tile(game, "./textures/enemy2.xpm",
					game->coords.x * SIZE, game->coords.y * SIZE);
				usleep(100000);
			}
		}
	}
	return (0);
}

/// @brief Lose function
/// @param game Struct of the game
void	lose(t_game *game)
{
	ft_printf("\n\n%s\n", "Peace is a lie, there is only passion.");
	ft_printf("%s\n", "Through passion, I gain strength.");
	ft_printf("%s\n", "Through strength, I gain power.");
	ft_printf("%s\n", "Through power, I gain victory.");
	ft_printf("%s\n", "Through victory, my chains are broken.");
	ft_printf("%s\n\n", "The Force shall set me free.");
	ft_printf("%s\n", "The Sith will rule the galaxy");
	ft_printf("%s\n", "And there is nothing you can do about it...");
	ft_printf("%s\n\n", "-------You died-------");
	ft_exit(game);
}

/// @brief Checks if the player collided with enemies based on the direction 
/// @param game Struct of the game
/// @param n Direction (Left and Down)
void	check_lose2(t_game *game, int n)
{
	if (n == 4)
	{
		if (game->map[game->player.y][game->player.x - 1] == 'X'
		|| (game->map[game->player.y][game->player.x - 1] == 'E'
			&& game->spawn == 1))
			lose(game);
	}
	if (n == 3)
	{
		if (game->map[game->player.y + 1][game->player.x] == 'X'
		|| (game->map[game->player.y + 1][game->player.x] == 'E'
			&& game->spawn == 1))
			lose(game);
	}
}

/// @brief Checks if the player collided with enemies based on the direction 
/// @param game Struct of the game
/// @param n Direction (Right and UP)
void	check_lose(t_game *game, int n)
{
	if (n == 1)
	{
		if (game->map[game->player.y - 1][game->player.x] == 'X'
		|| (game->map[game->player.y - 1][game->player.x] == 'E'
			&& game->spawn == 1))
			lose(game);
	}
	if (n == 2)
	{
		if (game->map[game->player.y][game->player.x + 1] == 'X'
		|| (game->map[game->player.y][game->player.x + 1] == 'E'
			&& game->spawn == 1))
			lose(game);
	}
	if (n > 2)
		check_lose2(game, n);
}
/**@}*/