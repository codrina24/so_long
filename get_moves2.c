/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_moves2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coholbur <coholbur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:49:13 by coholbur          #+#    #+#             */
/*   Updated: 2025/04/21 15:48:36 by coholbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_player(t_game *game, int new_pos_x, int new_pos_y)
{
	t_point	*pos;

	pos = &game->map.start_pos;
	mlx_put_image_to_window(game->mlx, game->win,
		game->backgr, pos->x * 64, pos->y * 64);
	pos->x = new_pos_x;
	pos->y = new_pos_y;
	mlx_put_image_to_window(game->mlx, game->win,
		game->player, pos->x * 64, pos->y * 64);
	game->nb_moves++;
	ft_putstr_fd("Moves: ", 2);
	ft_putnbr_fd(game->nb_moves, 2);
	ft_putstr_fd("\n", 2);
}

int	ft_direction(int keycode, t_game *game)
{
	if (keycode == 65307)
		ft_free_game(game);
	else if (keycode == 97)
		ft_move_left(game);
	else if (keycode == 100)
		ft_move_right(game);
	else if (keycode == 119)
		ft_move_up(game);
	else if (keycode == 115)
		ft_move_down(game);
	return (0);
}
