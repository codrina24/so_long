/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coholbur <coholbur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:00:25 by coholbur          #+#    #+#             */
/*   Updated: 2025/04/24 16:56:55 by coholbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_rectangular(t_map *map)
{
	ft_putstr_fd("Error\nNot rectangular\n", 2);
	ft_free_tmap(map);
}

void	ft_error_not_valid_char(t_map *map)
{	
	ft_putstr_fd("Error\n Not a valid char\n", 2);
	ft_free_tmap(map);
	exit(2);
}

void	ft_error_walls(t_map *map)
{
	ft_putstr_fd("Error\nWalls KO\n", 2);
	ft_free_tmap(map);
	exit(2);
}

void	ft_error_way(t_map *map, t_map *copy)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("This way is not possible\n", 2);
	ft_freee_tmap(copy);
	ft_free_tmap(map);
	exit(2);
}

void	ft_error_map(char *line_copy)
{
	ft_putstr_fd("Error\nError allocation new map\n", 2);
	if (line_copy)
		free(line_copy);
}
