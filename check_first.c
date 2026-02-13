/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coholbur <coholbur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:41:38 by coholbur          #+#    #+#             */
/*   Updated: 2025/04/21 13:46:54 by coholbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_rectangular(t_map *map)
{
	int	i;
	int	len_first_line;
	int	len;
	int	last_line;

	i = 0;
	len_first_line = ft_strlen(map->mapp[0]);
	len = 0;
	last_line = ft_strlen((map->mapp[map->row -1])) + 1;
	while (map->mapp[i])
	{		
		len = ft_strlen(map->mapp[i]);
		if (map->mapp[i] == map->mapp[map->row -1])
				len = last_line;
		if (len_first_line != len)
		{
			ft_error_rectangular(map);
			exit(2);
		}
		i++;
	}
}

int	ft_valid_chars(char z)
{
	if (z == '0' || z == '1' || z == 'P' || z == 'E' || z == 'C')
		return (0);
	return (1);
}

void	ft_check_valid_char(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	if (map == NULL || map->mapp[i] == NULL)
		return ;
	while (map->mapp[i] != NULL)
	{
		j = 0;
		while (map->mapp[i][j] != '\0')
		{
			if (map->mapp[i][j] == '\n')
			{
				j++;
				continue ;
			}
			else if (ft_valid_chars(map->mapp[i][j]) == 1)
				ft_error_not_valid_char(map);
			j++;
		}
		i++;
	}
}

int	ft_check_pos(t_map *map, char z, t_point *pos)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map->mapp[i] != NULL)
	{
		j = 0;
		while (map->mapp[i][j] != '\0')
		{
			if (map->mapp[i][j] == z)
			{
				pos->y = i;
				pos->x = j;
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

int	ft_check_print(int count, char z)
{
	if (count < 1)
	{
		ft_putstr_fd("Error\nNo character found \n", 2);
		ft_putchar_fd(z, 2);
		ft_putchar_fd('\n', 2);
		return (1);
	}
	else if (count > 1 && z != 'C')
	{
		ft_putstr_fd("Error\nMore than one character found \n", 2);
		ft_putchar_fd(z, 2);
		ft_putchar_fd('\n', 2);
		return (1);
	}
	return (0);
}
