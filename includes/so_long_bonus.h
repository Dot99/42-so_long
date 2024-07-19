/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:34:18 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/19 10:41:52 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * Bonus Part
 * @file so_long_bonus.h
 * @brief Bonus Program Header
*/

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../lib/libft/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

# define MAP_ERROR "Failed to open map"
# define MAP_ERROR_EX "Map extension not allowed"
# define MAP_ERROR_PATH "Map path is wrong"
# define WRONG_SIZE_MAP "Size of the map is incorrect"
# define WRONG_MAP_FORMAT "Format of map is incorrect"
# define WRONG_MALLOC "An error happened in a malloc"
# define WRONG_NUM "Number of player,exit or collectible is wrong"
# define MLX_ERROR "There has been an error on MLX"

/// @brief Tile Size
# define SIZE 64 

//------------------STRUCTS----------------------//

/// @brief Struct for coordinates of the map
/// @param x X coord
/// @param y Y coord
typedef struct s_coord
{
	int	x;
	int	y;
}				t_point;

/// @brief Struct for image/Necessary for MLX
/// @param mlx_img MLX Image
/// @param bpp Bytes per Pixel
/// @param line_len Necessary for MLX
/// @param endian Necessary for MLX
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

/// @brief Base struct for the game
/// @param map Matrix of coords
/// @param player Coords of player
/// @param width X value of the map
/// @param height Y value of the map
/// @param collectibles Collectibles on the map
/// @param gathered Util for flood_fill
/// @param collected Collectibles colleted on the map
/// @param moves Num of moves
/// @param coords t_point coords
/// @param player t_point coords of player
/// @param exit t_point coords of exit
/// @param tile t_point coords of tiles
/// @param mlx_ptr MLX Pointer
/// @param win_ptr Window Pointer
/// @param img Img Info
/// @param lightsaber Checker for collectible lightsaber
/// @param enemies Number of enemies
/// @param spawn Checker for boss spawn
/// @param health Checks the boss health
/// @param movement Number of movements when boss spawns
typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		collectibles;
	int		gathered;
	int		collected;
	int		moves;
	t_point	coords;
	t_point	player;
	t_point	exit;
	t_point	tile;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		lightsaber;
	int		enemies;
	int		spawn;
	int		health;
	int		movement;
}				t_game;

//-------------------FUNCTIONS-----------------//

//---------GENERAL---------//

void	dead(int num, t_game *game);
void	free_all(t_game *game);
int		ft_exit(t_game *game);
void	free_array(char **map, int lines);
int		ft_n_strclen(const char *str);

//---------MAP STUFF---------//

t_game	*init(void);
void	read_map(char *file, t_game *game);
void	check_extension(char *file);
void	map_validation(t_game *game);
void	check_map_size(t_game *game);
void	check_borders(t_game *game);
void	check_map_content(t_game *game);
void	check_valid_path(t_game *game);
void	check_map_assets(t_game *game);
void	check_collectibles(t_game *game);
void	fill_map(int fd, t_game *game);
void	init_game(t_game *game);
void	init_img(t_game *game);

//---------Render---------//

void	render(t_game *game);
void	render_window(t_game *game);
void	render_map(t_game *game);
void	put_tile(t_game *game, char *tile, int x, int y);
void	render_corners(t_game *game, int x, int y);
void	render_borders(t_game *game, int x, int y);
void	render_tiles(t_game *game, int x, int y);
void	render_moves(t_game *game);

//---------MOVEMENT---------//

int		handle_keypress(int keysym, t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	validate_move_up(t_game *game);
void	validate_move_down(t_game *game);
void	validate_move_left(t_game *game);
void	validate_move_right(t_game *game);

//---------ATTACK---------//

void	attack(int keysym, t_game *game);
void	lightsaber(t_game *game);
int		check_attack(t_game *game, int n);

//---------ENEMY---------//

void	check_lose(t_game *game, int n);
int		render_anim(t_game *game);
int		check_enemy(t_game *game, int n);
void	lose(t_game *game);

//---------BOSS---------//

void	put_health(t_game *game, int health);
void	check_boss_start(t_game *game);
void	boss_damage(t_game *game, int n);
int		check_boss(t_game *game, int n);
void	boss_anim(t_game *game, int n);

#endif

/**@}*/