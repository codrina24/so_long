/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coholbur <coholbur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:16:42 by coholbur          #+#    #+#             */
/*   Updated: 2025/04/21 14:43:00 by coholbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_clean_image(t_game *game)
{
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->backgr)
		mlx_destroy_image(game->mlx, game->backgr);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->coll)
		mlx_destroy_image(game->mlx, game->coll);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	ft_safe_point(game);
}

void	ft_free_game(t_game *game)
{
	ft_clean_image(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_free_map(game->map.mapp);
	ft_safe_point2(game);
	exit(0);
}

int	ft_check_exit(t_game *game)
{
	t_point	*pos;

	pos = &game->map.start_pos;
	if (game->nbr_to_collect == game->count_collected
		&& game->map.mapp[pos->y][pos->x] == 'E')
		ft_free_game(game);
	return (0);
}

int	ft_handle_cross(t_game *game)
{
	ft_free_game(game);
	return (0);
}

void	ft_setup_hooks(t_game *game)
{
	mlx_key_hook(game->win, ft_direction, game);
	mlx_hook(game->win, 17, StructureNotifyMask, ft_handle_cross, game);
}
