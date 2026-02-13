/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_moves1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coholbur <coholbur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:44:15 by coholbur          #+#    #+#             */
/*   Updated: 2025/04/21 16:36:27 by coholbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	ft_check_move(t_game *game, char dir)
{
	t_point	*pos;

	pos = &game->map.start_pos;
	if (dir == 'R' && game->map.mapp[pos->y][pos->x + 1] == '1')
		return (false);
	else if (dir == 'L' && game->map.mapp[pos->y][pos->x - 1] == '1')
		return (false);
	else if (dir == 'U' && game->map.mapp[pos->y - 1][pos->x] == '1')
		return (false);
	else if (dir == 'D' && game->map.mapp[pos->y + 1][pos->x] == '1')
		return (false);
	return (true);
}

void	ft_move_right(t_game *game)
{
	t_point	*pos;

	pos = &game->map.start_pos;
	if (ft_check_move(game, 'R'))
	{
		if (game->map.mapp[pos->y][pos->x + 1] == 'C')
		{
			game->map.mapp[pos->y][pos->x + 1] = '0';
			game->count_collected++;
		}
		else if (game->map.mapp[pos->y][pos->x + 1] == 'E')
		{
			if (game->count_collected != game->nbr_to_collect)
				return ;
		}
		ft_move_player(game, pos->x + 1, pos->y);
		ft_check_exit(game);
	}
}

void	ft_move_left(t_game *game)
{
	t_point	*pos;

	pos = &game->map.start_pos;
	if (ft_check_move(game, 'L'))
	{
		if (game->map.mapp[pos->y][pos->x - 1] == 'C')
		{
			game->map.mapp[pos->y][pos->x - 1] = '0';
			game->count_collected++;
		}
		else if (game->map.mapp[pos->y][pos->x - 1] == 'E')
		{
			if (game->count_collected != game->nbr_to_collect)
				return ;
		}
		ft_move_player(game, pos->x - 1, pos->y);
		ft_check_exit(game);
	}
}

void	ft_move_up(t_game *game)
{
	t_point	*pos;

	pos = &game->map.start_pos;
	if (ft_check_move(game, 'U'))
	{
		if (game->map.mapp[pos->y - 1][pos->x] == 'C')
		{
			game->map.mapp[pos->y - 1][pos->x] = '0';
			game->count_collected++;
		}
		else if (game->map.mapp[pos->y - 1][pos->x] == 'E')
		{
			if (game->count_collected != game->nbr_to_collect)
				return ;
		}
		ft_move_player(game, pos->x, pos->y - 1);
		ft_check_exit(game);
	}
}

void	ft_move_down(t_game *game)
{
	t_point	*pos;

	pos = &game->map.start_pos;
	if (ft_check_move(game, 'D'))
	{
		if (game->map.mapp[pos->y + 1][pos->x] == 'C')
		{
			game->map.mapp[pos->y + 1][pos->x] = '0';
			game->count_collected++;
		}
		else if (game->map.mapp[pos->y + 1][pos->x] == 'E')
		{
			if (game->count_collected != game->nbr_to_collect)
				return ;
		}
		ft_move_player(game, pos->x, pos->y + 1);
		ft_check_exit(game);
	}
}
