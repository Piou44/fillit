/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:04:00 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/08 13:35:51 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			free_map(char **map, int cote)
{
	int		i;

	i = 0;
	while (i < cote)
		free(map[i++]);
	free(map);
	return (0);
}


void		ft_erase(char **map, char c, int cote)
{
	int		x;
	int		y;

	y = 0;
	while (y < cote)
	{
		x = 0;
		while (x < cote)
		{
			if (map[y][x] == c)
				map[y][x] = '.';
			x++;
		}
		y++;
	}
}
