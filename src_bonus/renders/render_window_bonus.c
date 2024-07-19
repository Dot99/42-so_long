/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_window_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 08:59:10 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/19 15:42:12 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * @{
 * @file render_window_bonus.c
 * @brief Main function to render and render of the window
 */

#include "so_long_bonus.h"

/// @brief Renders the game
/// @param game Struct of the game
void	render_window(t_game *game)
{
	if (game->mlx_ptr == NULL)
		dead(8, game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, (game->width * SIZE),
			((game->height + 1) * SIZE), "so_long");
	if (game->win_ptr == NULL)
		dead(8, game);
	game->img.mlx_img = mlx_new_image(game->mlx_ptr, game->width * SIZE,
			game->height * SIZE);
	game->img.addr = mlx_get_data_addr(game->img.mlx_img, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
}

/// @brief Renders the window and map
/// @param game 
void	render(t_game *game)
{
	render_window(game);
	if (!game->win_ptr)
		dead(8, game);
	render_map(game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &handle_keypress, game);
	mlx_hook(game->win_ptr, DestroyNotify, StructureNotifyMask, &ft_exit,
		game);
	mlx_loop_hook(game->mlx_ptr, render_anim, game);
	mlx_loop(game->mlx_ptr);
}

/**@}*/