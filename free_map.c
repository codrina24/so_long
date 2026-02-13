/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coholbur <coholbur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:19:47 by coholbur          #+#    #+#             */
/*   Updated: 2025/04/21 14:21:37 by coholbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_pos(t_map *map)
{
	ft_free_tmap(map);
	exit(2);
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_free_tmap(t_map *map)
{
	if (!map)
		return ;
	if (map->mapp)
	{
		ft_free_map(map->mapp);
		map->mapp = NULL;
	}
}

void	ft_freee_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_freee_tmap(t_map *map)
{
	if (!map)
		return ;
	if (map->mapp)
	{
		ft_freee_map(map->mapp);
		map->mapp = NULL;
	}
	free(map);
}
