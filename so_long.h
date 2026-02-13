/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coholbur <coholbur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:57:41 by coholbur          #+#    #+#             */
/*   Updated: 2025/04/24 16:31:45 by coholbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define P "./textures/player.xpm"
# define E "./textures/exit.xpm"
# define B "./textures/background.xpm"
# define W "./textures/wall.xpm"
# define C "./textures/collect.xpm"

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_map
{
	char	**mapp;
	int		row;
	int		col;
	int		count_lines;
	int		nbr_to_collect;
	t_point	start_pos;
	t_point	exit_pos;
	t_point	collect_pos;

}					t_map;

typedef struct s_game
{
	int		width;
	int		height;
	void	*mlx;
	void	*win;
	t_map	map;
	void	*player;
	void	*backgr;
	void	*start;
	void	*exit;
	void	*coll;
	void	*wall;
	int		nb_moves;
	int		nbr_to_collect;
	int		count_collected;

}				t_game;

void	ft_free_map(char **map);
void	ft_free_tmap(t_map *map);
void	ft_freee_map(char **map);
void	ft_freee_tmap(t_map *map);
void	ft_free_pos(t_map *map);
void	ft_error_rectangular(t_map *map);
void	ft_error_not_valid_char(t_map *map);
void	ft_error_walls(t_map *map);
void	ft_error_way(t_map *map, t_map *copy);
void	ft_error_map(char *line_copy);
void	ft_error_size_map(t_map *map);
void	ft_error_display_size(t_game *game);
void	ft_error_size(int img_width, int img_height, char *name, t_game *game);
void	ft_error_img_loaded(t_game *game);
int		ft_open(char *file);
char	**ft_new_map(t_map *map);
int		ft_add_line_to_map(t_map *map, char *line);
int		ft_read_map_from_file(t_map *map, char *file);
void	ft_init_tmap(t_map *map);
t_map	*ft_copy_tmap(t_map *map);
void	ft_safe_point(t_game *game);
void	ft_safe_point2(t_game *game);
void	ft_print_map(t_map *map);
void	ft_get_rows(t_map *map);
void	ft_get_cols(t_map *map);
char	*ft_first_vertical_line(t_map *map);
char	*ft_last_vertical_line(t_map *map);
int		ft_check_extension(char *file);
void	ft_check_arg(int argc, char **argv);
void	ft_check_rectangular(t_map *map);
int		ft_valid_chars(char z);
void	ft_check_valid_char(t_map *map);
int		ft_check_pos(t_map *map, char z, t_point *pos);
int		ft_check_print(int count, char z);
void	ft_check_allpos(t_map *map);
void	ft_count_collectible(t_map *map);
void	ft_check_top_and_bottom(t_map *map);
void	ft_check_left_and_right(t_map *map);
void	ft_check_walls(t_map *map);
void	ft_flood_fill(char **map, t_point pos, char z);
void	ft_possible_map(t_map *map);
void	ft_check_tmap(t_map *map);
void	ft_check_size(t_map *map);
void	ft_init_tgame(t_game *game, t_map *map);
void	ft_error_mlx_init(t_game *game);
void	ft_error_create_win(t_game *game);
void	ft_clean_image(t_game *game);
void	ft_free_game(t_game *game);
int		ft_check_exit(t_game *game);
int		ft_handle_cross(t_game *game);
void	ft_setup_hooks(t_game *game);
int		ft_check_display_size(t_game *game);
void	ft_file_to_image(t_game *game);
void	ft_render(int i, int j, t_game *game);
void	ft_img_add(t_game *game);
void	ft_define_dir(t_point *pos, t_game *game, char z);
bool	ft_check_move(t_game *game, char dir);
void	ft_move_player(t_game *game, int new_pos_x, int new_pos_y);
int		ft_direction(int keycode, t_game *game);
void	ft_move_right(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);

#endif
