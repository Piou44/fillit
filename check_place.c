/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 13:40:31 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/11 17:11:44 by fhuang           ###   ########.fr       */
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

t_list	*find_my_tetris(t_list **lst, char alpha)
{
	while (*lst)
	{
		if (((t_maillon*)((*lst)->content))->n_tetris == alpha)
			return (*lst);
		*lst = (*lst)->next;
	}
	return (0);
}

void	cpy_maillon(char **grid, t_maillon *tetris)
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

	if (tetris->y + tetris->ver > cote || tetris->x + tetris->hor > cote)
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
	cpy_maillon(grid, tetris);
	print_map(grid, cote);
	ft_putchar('\n');
	sleep(1);
	return (0);
}
