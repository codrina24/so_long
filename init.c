/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coholbur <coholbur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:51:12 by coholbur          #+#    #+#             */
/*   Updated: 2025/04/21 16:40:21 by coholbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_tmap(t_map *map)
{
	ft_memset(map, 0, sizeof(t_map));
	map->mapp = NULL;
	map->count_lines = 0;
	map->nbr_to_collect = 0;
	map->row = 0;
	map->col = 0;
	map->start_pos.x = -1;
	map->start_pos.y = -1;
	map->exit_pos.x = -1;
	map->exit_pos.y = -1;
	map->collect_pos.x = -1;
	map->collect_pos.y = -1;
}

void	ft_init_tgame(t_game *game, t_map *map)
{
	t_map	*copied;

	copied = ft_copy_tmap(map);
	if (!copied || !copied->mapp)
	{
		ft_putstr_fd("Error\nError: Failed to copy the map!\n", 2);
		exit(1);
	}
	game->map = *copied;
	free(copied);
	game->mlx = NULL;
	game->win = NULL;
	game->width = game->map.col;
	game->height = game->map.row;
	game->player = NULL;
	game->backgr = NULL;
	game->start = NULL;
	game->exit = NULL;
	game->coll = NULL;
	game->wall = NULL;
	game->nb_moves = 0;
	game->nbr_to_collect = map->nbr_to_collect;
	game->count_collected = 0;
}

t_map	*ft_copy_tmap(t_map *map)
{
	t_map	*copy;
	char	**new;

	copy = malloc(sizeof(t_map));
	if (!copy)
		return (NULL);
	new = ft_bucketstr_copy(map->mapp);
	if (!new)
	{
		free(copy);
		return (NULL);
	}
	copy->nbr_to_collect = map->nbr_to_collect;
	copy->row = map->row;
	copy->col = map->col;
	copy->count_lines = map->count_lines;
	copy->start_pos = map->start_pos;
	copy->exit_pos = map->exit_pos;
	copy->collect_pos = map->collect_pos;
	copy->mapp = new;
	return (copy);
}

void	ft_safe_point(t_game *game)
{
	game->player = NULL;
	game->backgr = NULL;
	game->exit = NULL;
	game->coll = NULL;
	game->wall = NULL;
}

void	ft_safe_point2(t_game *game)
{
	game->win = NULL;
	game->mlx = NULL;
	game->nb_moves = 0;
	game->nbr_to_collect = 0;
	game->count_collected = 0;
}
