/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coholbur <coholbur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:57:24 by coholbur          #+#    #+#             */
/*   Updated: 2025/04/24 16:56:44 by coholbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_rows(t_map *map)
{
	int	i;
	int	count;

	if (!map || !map->mapp)
		return ;
	i = 0;
	count = 0;
	while (map->mapp[i])
	{
		count++;
		i++;
	}
	map->row = count;
}

void	ft_get_cols(t_map *map)
{
	int	len;

	if (map->row > 0)
	{
		len = ft_strlen(map->mapp[0]);
		map->col = len - 1;
	}
	else
		map->col = 0;
}

char	*ft_first_vertical_line(t_map *map)
{
	int		i;
	char	*result;

	if (map->mapp == NULL)
		return (NULL);
	result = (char *)malloc((map->row + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < map->row)
	{
		result[i] = map->mapp[i][0];
		if (result[i] != '1')
		{
			free(result);
			return (NULL);
		}
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_last_vertical_line(t_map *map)
{
	int		i;
	int		len;
	char	*result;

	i = 0;
	len = ft_strlen(map->mapp[0]) - 1;
	result = (char *)malloc((map->row + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (i < map->row)
	{
		result[i] = map->mapp[i][len - 1];
		if (result[i] != '1')
		{
			free(result);
			return (NULL);
		}
		i++;
	}
	result[i] = '\0';
	return (result);
}

void	ft_error_img_loaded(t_game *game)
{
	ft_clean_image(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_free_map(game->map.mapp);
	ft_safe_point2(game);
	exit(1);
}
