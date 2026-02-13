/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coholbur <coholbur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:26:07 by coholbur          #+#    #+#             */
/*   Updated: 2025/04/21 14:12:54 by coholbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	ft_open(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n", 2);
		perror("Error open");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

char	**ft_new_map(t_map *map)
{
	char	**new_map;
	int		i;

	i = 0;
	new_map = (char **)malloc(sizeof(char *) * (map->count_lines + 2));
	if (!new_map)
		return (ft_putstr_fd("Error\nError malloc new_line\n", 2), NULL);
	while (i < map->count_lines)
	{
		new_map[i] = map->mapp[i];
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

int	ft_add_line_to_map(t_map *map, char *line)
{
	char	**new_map;
	char	*line_copy;

	line_copy = ft_strdup(line);
	if (!line_copy)
		return (ft_putstr_fd("Error\nError copy line\n", 2), 1);
	new_map = ft_new_map(map);
	if (!new_map)
	{
		free(new_map);
		return (ft_error_map(line_copy), 1);
	}
	new_map[map->count_lines] = line_copy;
	map->count_lines++;
	new_map[map->count_lines] = NULL;
	if (map->mapp)
	{
		free(map->mapp);
		map->mapp = NULL;
	}
	map->mapp = new_map;
	return (0);
}

int	ft_read_map_from_file(t_map *map, char *file)
{
	char	*line;
	int		fd;

	fd = ft_open(file);
	if (fd < 0)
		return (1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_add_line_to_map(map, line) == 1)
			return (free(line), close(fd), 1);
		free(line);
	}
	if (map->count_lines == 0)
		return (ft_putstr_fd("Error\n, Error empty map\n", 2), close(fd), 1);
	return (0);
}

void	ft_print_map(t_map *map)
{
	int	i;

	if (map == NULL || map->mapp == NULL)
		return ;
	i = 0;
	while (i < map->count_lines)
	{
		if (map->mapp[i] != NULL)
			ft_putstr_fd(map->mapp[i], 1);
		i++;
	}
	i = 0;
	while (i < map->count_lines)
	{
		free(map->mapp[i]);
		i++;
	}
	free(map->mapp);
	map->mapp = NULL;
}
