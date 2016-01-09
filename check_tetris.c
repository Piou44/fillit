/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetris.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 10:57:19 by asalama           #+#    #+#             */
/*   Updated: 2016/01/09 16:46:11 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		ft_alphabet(char alpha)
{
	static int		i = 1;
	static int		j = 0;

	if (alpha == '#')
	{
		if (j <= 4)
		{
			alpha = i + 64;
			j++;
		}
		if (j == 4)
		{
			i++;
			j = 0;
		}
	}
	if (i > 26)
		return (0);
	return (alpha);
}

int			count_connex(char **tab, int y, int x, int *connex)
{
	if (y != 3 && tab[y + 1][x] == '#')
		(*connex)++;
	if (y != 0 && tab[y - 1][x] == '#')
		(*connex)++;
	if (x != 3 && tab[y][x + 1] == '#')
		(*connex)++;
	if (x != 0 && tab[y][x - 1] == '#')
		(*connex)++;
	if (!(tab[y][x] = ft_alphabet(tab[y][x])))
		return (0);
	return (1);
}

int			check_diese(char **tab)
{
	int		x;
	int		y;
	int		connex;
	int		diese;

	y = 0;
	connex = 0;
	diese = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tab[y][x] == '#')
			{
				if (!(count_connex(tab, y, x, &connex)))
					return (0);
				diese++;
			}
			x++;
		}
		y++;
	}
	return (((connex == 3) || (connex == 4)) && diese == 4 ? 1 : 0);
}

int			check_tetris(char **tab)
{
	int		x;
	int		y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tab[y][x] != '.' && tab[y][x] != '#')
				return (0);
			x++;
		}
		y++;
	}
	return (check_diese(tab));
}
