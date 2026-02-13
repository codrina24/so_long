/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coholbur <coholbur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:40:14 by coholbur          #+#    #+#             */
/*   Updated: 2025/04/21 13:41:26 by coholbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5)
		return (-1);
	else if (len >= 5 && ft_strcmp(&file[len - 4], ".ber") == 0)
	{
		if (file[0] == '.' && len == 4)
			return (1);
		return (0);
	}
	return (1);
}

void	ft_check_arg(int argc, char **argv)
{
	if (argc != 2 || argv[1] == NULL)
	{
		ft_putstr_fd("Error\nError arg\n", 2);
		exit(1);
	}
	if (ft_check_extension(argv[1]) != 0)
	{
		ft_putstr_fd("Error\nError arg\n", 2);
		exit(1);
	}
}
