/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:30:39 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/19 15:43:09 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * @file main_bonus.c
 * @brief Main of the program
 */

#include "so_long_bonus.h"

/**
 * @brief Main
 * 
 * @param argc Number of arguments 
 * @param argv Content of arguments
 */
int	main(int argc, char **argv)
{
	int		fd;
	t_game	*game;

	game = NULL;
	if (argc == 2)
	{
		check_extension(argv[1]);
		game = init();
		fd = open (argv[1], O_RDONLY);
		if (fd < 0)
			dead(1, game);
		read_map(argv[1], game);
		map_validation(game);
		render(game);
		ft_exit(game);
	}
	return (0);
}

/**@}*/