/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouthie <jrouthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 12:24:52 by jrouthie          #+#    #+#             */
/*   Updated: 2015/07/19 11:51:32 by jrouthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"
#include <unistd.h>

int		error(void);
int		transfert(char **argv, char tab[9][9]);

int		main(int argc, char **argv)
{
	char	tab[9][9];
	char	res[9][9];
	int		nbs;

	if (argc != 10 || transfert(argv, tab) == 0)
		return (error());
	ft_solve(tab, 0, res, &nbs);
	if (nbs != 1)
		return (error());
	else
		ft_printtab(res);
	return (0);
}

int		transfert(char **argv, char tab[9][9])
{
	int x;
	int y;

	x = 0;
	while (x++ < 9)
	{
		y = -1;
		while (y++ < 8 || argv[x][y] != '\0')
		{
			if (y >= 9 || argv[x][y] == '\0')
				return (0);
			else if (argv[x][y] >= '1' && argv[x][y] <= '9')
				tab[x - 1][y] = argv[x][y];
			else if (argv[x][y] != '.')
				return (0);
			else
				tab[x - 1][y] = '0';
		}
	}
	return (1);
}

int		error(void)
{
	write(1, "Erreur\n", 7);
	return (0);
}
