/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coholbur <coholbur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:58:13 by coholbur          #+#    #+#             */
/*   Updated: 2025/03/04 17:54:05 by coholbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
/*
int     main(int argc, char **argv)
{
        int r;
        int i;

	r = 0;
        i = ft_strcmp(argv[1], argv[2]);
                printf("%d\n", i);
        if (argc < 3)
        {
                fprintf(stderr, "%s\n", argv[0]);
                exit(EXIT_FAILURE);
        }

        if  (argc == 3)

                r = ft_strcmp(argv[1], argv[2]);

        if (r == 0)
        {
                printf("s1 = s2\n");
        }
        else if (r  < 0 )
        {
                printf("s1 < s2(%d)\n", r);
        }
        else
        {
                printf("s1 > s2(%d)\n", r);
        }
        exit(EXIT_SUCCESS);
}
*/
