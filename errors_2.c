/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coholbur <coholbur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:01:30 by coholbur          #+#    #+#             */
/*   Updated: 2025/04/21 14:16:12 by coholbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_size_map(t_map *map)
{
	ft_putstr_fd("Error\n,TOO SMALL", 2);
	ft_free_tmap(map);
	exit(2);
}

void	ft_error_size(int img_width, int img_height, char *name, t_game *game)
{
	if (img_width != 64 && img_height != 64)
	{
		ft_putstr_fd("Error\nSize KO for texture:\n", 2);
		ft_putstr_fd(name, 2);
		ft_putstr_fd("\n", 2);
		ft_clean_image(game);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		ft_free_map(game->map.mapp);
		ft_safe_point2(game);
		exit(2);
	}
}

void	ft_error_display_size(t_game *game)
{
	ft_putstr_fd("Error\nMap dimensions exceed display limits\n", 2);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_free_tmap(&game->map);
	ft_safe_point2(game);
	exit(2);
}

void	ft_error_mlx_init(t_game *game)
{
	ft_putstr_fd("Error\nMlx_init failed\n", 2);
	ft_free_map(game->map.mapp);
	ft_safe_point2(game);
	exit(3);
}

void	ft_error_create_win(t_game *game)
{
	ft_putstr_fd("Error\nMlx_create failed\n", 2);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_free_map(game->map.mapp);
	ft_safe_point2(game);
	exit (3);
}
