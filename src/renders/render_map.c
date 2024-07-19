/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 09:34:38 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/19 10:38:08 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup mandatory Mandatory
 * @file render_map.c
 * @brief Renders of the map and function to set images on the tiles
 */

#include "so_long.h"

/// @brief Function to put a image to a tile
/// @param game Struct of the game
/// @param tile Coords of the tile
/// @param x X coord
/// @param y Y coord
void	put_tile(t_game *game, char *tile, int x, int y)
{
	if (game->img.mlx_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->img.mlx_img);
		game->img.mlx_img = 0;
	}
	game->img.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, tile,
			&game->tile.x, &game->tile.y);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img.mlx_img, x, y);
}

/// @brief Render the corners of the map
/// @param game Struct of the game
/// @param x X coord
/// @param y Y coord
void	render_corners(t_game *game, int x, int y)
{
	if (y == 0 && x == 0)
		put_tile(game, "./textures/corner_top_left.xpm", x * SIZE, y * SIZE);
	else if (y == 0 && x == game->width - 1)
		put_tile(game, "./textures/corner_top_right.xpm", x * SIZE, y * SIZE);
	else if (y == game->height - 1 && x == 0)
		put_tile(game, "./textures/corner_bottom_left.xpm", x * SIZE, y * SIZE);
	else if (y == game->height - 1 && x == game->width - 1)
		put_tile(game, "./textures/corner_bottom_right.xpm",
			x * SIZE, y * SIZE);
}

/// @brief Render the borders
/// @param game Struct of the game
/// @param x X coord
/// @param y Y coord
void	render_borders(t_game *game, int x, int y)
{
	if (y == 0 && x > 0 && x < game->width - 1)
		put_tile(game, "./textures/wall_top.xpm", x * SIZE, y * SIZE);
	else if (y > 0 && y < game->height - 1 && x == 0)
		put_tile(game, "./textures/wall_left.xpm", x * SIZE, y * SIZE);
	else if (y > 0 && y < game->height - 1 && x == game->width - 1)
		put_tile(game, "./textures/wall_right.xpm", x * SIZE, y * SIZE);
	else if (y == game->height - 1 && x > 0 && x < game->width - 1)
		put_tile(game, "./textures/wall_bottom.xpm", x * SIZE, y * SIZE);
}

/// @brief Render the tiles
/// @param game Struct of the game
/// @param x X coord
/// @param y Y coord
void	render_tiles(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map[y][x];
	if (tile == '1' && y > 0 && y < game->height - 1
		&& x > 0 && x < game->width - 1)
		put_tile(game, "./textures/block.xpm", x * SIZE, y * SIZE);
	if (tile == '0')
		put_tile(game, "./textures/floor.xpm", x * SIZE, y * SIZE);
	else if (tile == 'P')
		put_tile(game, "./textures/player.xpm", x * SIZE, y * SIZE);
	else if (tile == 'E')
		put_tile(game, "./textures/exit.xpm", x * SIZE, y * SIZE);
	else if (tile == 'C')
		put_tile(game, "./textures/collectible.xpm", x * SIZE, y * SIZE);
}

/// @brief Main function to render the map
/// @param game Struct of the game
void	render_map(t_game *game)
{
	game->coords.y = -1;
	while (++game->coords.y < game->height)
	{
		game->coords.x = -1;
		while (++game->coords.x < game->width)
		{
			render_corners(game, game->coords.x, game->coords.y);
			render_borders(game, game->coords.x, game->coords.y);
			render_tiles(game, game->coords.x, game->coords.y);
		}
	}
}

/**@}*/