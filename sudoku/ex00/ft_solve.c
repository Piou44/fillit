/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouthie <jrouthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 13:08:04 by jrouthie          #+#    #+#             */
/*   Updated: 2015/07/19 12:12:36 by jrouthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

void	tab_clone(char tab[9][9], char dest[9][9], int *nbs);

int		ft_solve(char tab[9][9], int pos, char res[9][9], int *nbs)
{
	int		x;
	int		y;
	int		c;

	if (pos == 81)
	{
		tab_clone(tab, res, nbs);
		return (1);
	}
	x = pos / 9;
	y = pos % 9;
	if (tab[x][y] != '0')
		return (ft_solve(tab, pos + 1, res, nbs));
	c = 0;
	while (c < 9 && *nbs < 2)
	{
		if (ft_testcase('1' + c, tab, x, y))
		{
			tab[x][y] = '1' + c;
			ft_solve(tab, pos + 1, res, nbs);
			tab[x][y] = '0';
		}
		c++;
	}
	return (0);
}

void	tab_clone(char tab[9][9], char dest[9][9], int *nbs)
{
	int	c;

	if (*nbs == 0)
	{
		c = 0;
		while (c < 81)
		{
			dest[c / 9][c % 9] = tab[c / 9][c % 9];
			c++;
		}
	}
	*nbs = *nbs + 1;
}
