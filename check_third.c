/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_third.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coholbur <coholbur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:53:32 by coholbur          #+#    #+#             */
/*   Updated: 2025/04/21 13:56:51 by coholbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill(char **map, t_point pos, char z)
{
	if (pos.y < 0 || pos.x < 0 || map[pos.y] == NULL
		|| map[pos.y][pos.x] == '\0' || map[pos.y][pos.x] == '1'
		|| map[pos.y][pos.x] == z)
		return ;
	map[pos.y][pos.x] = 'z';
	ft_flood_fill(map, (t_point){pos.x - 1, pos.y}, z);
	ft_flood_fill(map, (t_point){pos.x + 1, pos.y}, z);
	ft_flood_fill(map, (t_point){pos.x, pos.y - 1}, z);
	ft_flood_fill(map, (t_point){pos.x, pos.y + 1}, z);
}

void	ft_possible_map(t_map *map)
{
	t_map	*copy;
	t_point	pos;
	int		a;
	int		b;

	copy = ft_copy_tmap(map);
	if (!copy)
	{
		ft_putstr_fd("Error\nError copy t_map\n", 2);
		return ;
	}
	pos = copy->start_pos;
	if (!pos.x && !pos.y)
		ft_error_way(map, copy);
	ft_flood_fill(copy->mapp, pos, 'z');
	a = ft_check_pos(copy, 'E', &copy->exit_pos);
	b = ft_check_pos(copy, 'C', &copy->collect_pos);
	if (a != 0 || b != 0)
		ft_error_way(map, copy);
	ft_freee_tmap(copy);
}

void	ft_check_tmap(t_map *map)
{
	ft_get_rows(map);
	ft_get_cols(map);
	ft_check_size(map);
	ft_check_rectangular(map);
	ft_check_valid_char(map);
	ft_check_allpos(map);
	ft_count_collectible(map);
	ft_check_walls(map);
	ft_possible_map(map);
}

void	ft_check_size(t_map *map)
{
	int	len;
	int	len1;
	int	len2;

	len = map->row;
	len1 = map->col;
	len2 = len * len1;
	if ((len < 3 || len1 < 5) && (len2 < 15))
		ft_error_size_map(map);
	else if ((len == 3 && len1 < 5) || (len1 == 3 && len < 5))
		ft_error_size_map(map);
}
