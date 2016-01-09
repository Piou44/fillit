/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 13:40:31 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/09 18:50:52 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
void	where_is_my_dot(t_maillon *tetris, char **grid, int cote)
{
	while (ft_isupper(grid[tetris->y][tetris->x]))
	{
		tetris->x++;
		if (tetris->x == cote)
		{
			tetris->y++;
			tetris->x= 0;
		}
	}
}
*/

void	cpy_maillon(char **grid, t_maillon *tetris, int cote)
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
					grid[tetris->y + j][tetris->x + i] == '.')
				grid[tetris->y + j][tetris->x + i] = tetris->tab[j][i];
			i++;
		}
		j++;
	}
}

int		try_space(char **grid, t_maillon *tetris, int cote)
{
	int			i;
	int			j;

	if (tetris->y + tetris->ver > cote)
		return (2);
	if (tetris->x + tetris->hor > cote)
		return (1);
	j = 0;
	while (j < tetris->ver)
	{
		i = 0;
		while (i < tetris->hor)
		{
			if (ft_isupper(tetris->tab[j][i]) &&
					grid[tetris->y + j][tetris->x + i] != '.')
				return (1);
			i++;
		}
		j++;
	}
	cpy_maillon(grid, tetris, cote);
	return (0);
}
