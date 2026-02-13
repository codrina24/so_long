/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coholbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:22:08 by coholbur          #+#    #+#             */
/*   Updated: 2025/04/21 13:22:21 by coholbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"libft.h"

void	*ft_free(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return (NULL);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

int	ft_strlen_double(char **str_bucket)
{
	int	i;

	i = 0;
	if (str_bucket == NULL)
		return (0);
	while (str_bucket[i])
		i++;
	return (i);
}

char	**ft_bucketstr_copy(char **str)
{
	int		bucket_len;
	char	**copy;
	int		i;

	i = 0;
	bucket_len = ft_strlen_double(str);
	if (bucket_len == 0)
		return (NULL);
	copy = (char **)malloc((bucket_len + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	while (i < bucket_len)
	{
		copy[i] = ft_strdup(str[i]);
		if (!copy[i])
		{
			ft_free(copy);
			return (NULL);
		}
		i++;
	}
	copy[bucket_len] = NULL;
	return (copy);
}
