/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coholbur <coholbur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:21:51 by coholbur          #+#    #+#             */
/*   Updated: 2025/04/24 16:57:04 by coholbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_display_size(t_game *game)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	mlx_get_screen_size(game->mlx, &width, &height);
	if (width < game->width * 64)
		ft_error_display_size(game);
	if (height < game->height * 64)
		ft_error_display_size(game);
	return (0);
}

void	ft_file_to_image(t_game *game)
{
	int	img_width;
	int	img_height;

	img_width = 64;
	img_height = 64;
	game->backgr = mlx_xpm_file_to_image(game->mlx, B, &img_width, &img_height);
	ft_error_size(img_width, img_height, "Background", game);
	game->wall = mlx_xpm_file_to_image(game->mlx, W, &img_width, &img_height);
	ft_error_size(img_width, img_height, "Walls", game);
	game->player = mlx_xpm_file_to_image(game->mlx, P, &img_width, &img_height);
	ft_error_size(img_width, img_height, "Player", game);
	game->coll = mlx_xpm_file_to_image(game->mlx, C, &img_width, &img_height);
	ft_error_size(img_width, img_height, "Collect", game);
	game->exit = mlx_xpm_file_to_image(game->mlx, E, &img_width, &img_height);
	ft_error_size(img_width, img_height, "Exit", game);
	if ((!game->backgr || !game->wall || !game->player
			|| !game->coll || !game->exit))
		ft_error_img_loaded(game);
}

void	ft_render(int i, int j, t_game *game)
{
	i = 0;
	while (i < game->map.row)
	{
		j = 0;
		while (j <= game->map.col)
		{
			if (game->map.mapp[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win,
					game->backgr, j * 64, i * 64);
			else if (game->map.mapp[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->wall, j * 64, i * 64);
			else if (game->map.mapp[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win,
					game->player, j * 64, i * 64);
			else if (game->map.mapp[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->coll, j * 64, i * 64);
			else if (game->map.mapp[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->exit, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	ft_img_add(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_file_to_image(game);
	ft_render(i, j, game);
}
