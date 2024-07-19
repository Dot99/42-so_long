/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:42:02 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/19 15:41:03 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * @{
 * @file map_utils_bonus.c
 * @brief Fill the double array and define height and width
 */

#include "so_long_bonus.h"

/// @brief strclen different from gnl and libft
/// @param str String to check
/// @return The size of the string stop characters
int	ft_n_strclen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n' && str[i] != '\r')
		i++;
	return (i);
}

/**
 * @brief Count the number of lines in the file
 * 
 * @param fileName Name of the file
 * @return int Number of lines
 */
int	count_lines(char *fileName)
{
	int		i;
	int		fd;
	char	*tmp;

	i = 0;
	fd = open(fileName, O_RDONLY);
	if (fd < 0)
		dead(1, NULL);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

/// @brief Fills our game->map array
/// @param fd File name
/// @param game Struct of the game
void	fill_map(int fd, t_game *game)
{
	int		i;
	char	*temp;

	i = -1;
	while (++i < game->height)
		game->map[i] = get_next_line(fd);
	temp = get_next_line(fd);
	free(temp);
	game->map[i] = NULL;
}

/// @brief Reads the map
/// @param file Name of file
/// @param game Struct of the game
void	read_map(char *file, t_game *game)
{
	int	fd;

	game->height = count_lines(file);
	if (game->height <= 0)
		dead(4, game);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		dead(1, game);
	game->map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		dead(6, game);
	fill_map(fd, game);
	game->width = ft_n_strclen(game->map[0]);
	close(fd);
}

/**@}*/