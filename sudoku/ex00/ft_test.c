/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouthie <jrouthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 14:17:15 by jrouthie          #+#    #+#             */
/*   Updated: 2015/07/19 11:26:33 by jrouthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

int	ft_testcase(char i, char tab[9][9], int x, int y)
{
	return (ft_testzone(i, tab, x, y) && ft_testline(i, tab, x)
	&& ft_testcol(i, tab, y));
}

int	ft_testzone(char i, char tab[9][9], int x, int y)
{
	int zx;
	int zy;

	zx = x / 3 * 3;
	zy = y / 3 * 3;
	x = 0;
	while (x < 3)
	{
		y = 0;
		while (y < 3)
		{
			if (tab[zx + x][zy + y] == i)
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	ft_testline(char i, char tab[9][9], int line)
{
	int y;

	y = 0;
	while (y < 9)
	{
		if (tab[line][y] == i)
			return (0);
		y++;
	}
	return (1);
}

int	ft_testcol(char i, char tab[9][9], int col)
{
	int x;

	x = 0;
	while (x < 9)
	{
		if (tab[x][col] == i)
			return (0);
		x++;
	}
	return (1);
}
