/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_second.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coholbur <coholbur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:47:11 by coholbur          #+#    #+#             */
/*   Updated: 2025/04/24 16:20:59 by coholbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_allpos(t_map *map)
{
	int	count;

	count = ft_check_pos(map, 'P', &map->start_pos);
	if (ft_check_print(count, 'P'))
		ft_free_pos(map);
	count = ft_check_pos(map, 'E', &map->exit_pos);
	if (ft_check_print(count, 'E'))
		ft_free_pos(map);
	count = ft_check_pos(map, 'C', &map->collect_pos);
	if (ft_check_print(count, 'C'))
		ft_free_pos(map);
}

void	ft_count_collectible(t_map *map)
{
	int	nbr;

	nbr = ft_check_pos(map, 'C', &map->collect_pos);
	if (nbr == 0)
	{
		ft_putstr_fd("Error\n, No collectibles found.\n", 2);
		map->nbr_to_collect = 0;
		return ;
	}
	map->nbr_to_collect = nbr;
}

void	ft_check_top_and_bottom(t_map *map)
{
	int	len;
	int	i;

	len = ft_strlen(map->mapp[0]);
	i = 0;
	while (i < len - 1)
	{
		if (map->mapp[0][i] != '1')
			ft_error_walls(map);
		i++;
	}
	if (ft_strncmp(map->mapp[0], map->mapp[map->row - 1], len - 1) != 0)
		ft_error_walls(map);
}

void	ft_check_left_and_right(t_map *map)
{
	char	*first;
	char	*last;
	int		len;

	first = ft_first_vertical_line(map);
	if (!first)
		ft_error_walls(map);
	last = ft_last_vertical_line(map);
	if (!last)
	{
		free(first);
		ft_error_walls(map);
	}
	len = ft_strlen(first);
	if (ft_strncmp(first, last, len) != 0)
	{
		free(first);
		free(last);
		ft_error_walls(map);
	}
	free(first);
	free(last);
}

void	ft_check_walls(t_map *map)
{
	ft_check_top_and_bottom(map);
	ft_check_left_and_right(map);
}
