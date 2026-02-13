/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coholbur <coholbur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:54:18 by coholbur          #+#    #+#             */
/*   Updated: 2025/04/21 14:56:30 by coholbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_map	map;
	t_game	game;

	ft_init_tmap(&map);
	ft_check_arg(argc, argv);
	if (ft_read_map_from_file(&map, argv[1]) != 0)
		return (1);
	ft_check_tmap(&map);
	ft_init_tgame(&game, &map);
	ft_free_tmap(&map);
	game.mlx = mlx_init();
	if (!game.mlx)
		ft_error_mlx_init(&game);
	ft_check_display_size(&game);
	game.win = mlx_new_window(game.mlx, game.width * 64,
			game.height * 64, "GAME");
	if (!game.win)
		ft_error_create_win(&game);
	ft_img_add(&game);
	ft_setup_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}
