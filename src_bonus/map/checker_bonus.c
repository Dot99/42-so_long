/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:40:27 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/19 15:41:01 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * @{
 * @file checker_bonus.c
 * @brief Checks the extension of the file
 */

#include "so_long_bonus.h"

/// @brief Checks extension of file
/// @param file Name of file
void	check_extension(char *file)
{
	if (ft_strncmp(file + ft_strlen(file) - 4, ".ber", 4) != 0)
		dead(2, NULL);
}

/**@}*/