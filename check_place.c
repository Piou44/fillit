/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 13:40:31 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/08 19:22:05 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	where_is_my_dot(t_map *map, char **grid, int cote)
{
	while (ft_isupper(grid[map->y][map->x]))
	{
		map->x++;
		if (map->x == cote)
		{
			map->y++;
			map->x= 0;
		}
	}
}

void	cpy_maillon(char **grid, t_map *map, t_maillon *tetris, int cote)
{
	int		i;
	int		j;

	j = 0;
	while (j < tetris->ver)
	{
		i = 0;
		while (i < tetris->hor)
		{
			if (ft_isupper(tetris->tab[j][i]) &&
					grid[map->y + j][map->x + i] == '.')
				grid[map->y + j][map->x + i] = tetris->tab[j][i];
			i++;
		}
		j++;
	}
}

int		try_space(char **grid, t_map *map, t_maillon *tetris, int cote)
{
	int			i;
	int			j;

	if (map->y + tetris->ver > cote)
		return (1);
	if (map->x + tetris->hor > cote)
		return (1);

	j = 0;
	while (j < tetris->ver)
	{
		i = 0;
		while (i < tetris->hor)
		{
			if (ft_isupper(tetris->tab[j][i]) && 
					grid[map->y + j][map->x + i] != '.')
				return (1);
			i++;
		}
		j++;
	}
	cpy_maillon(grid, map, tetris, cote);
	return (0);
}
