/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetris.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:25:04 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/08 14:46:11 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

int		trim_ho(char **tab, int n)
{
	int		boo;
	int		x;

	boo = 0;
	x = 0;
	while (x < 4)
	{
		if (ft_strncmp(tab[x], "....", n) == 0)
		{
			if (boo)
				ft_bzero(tab[x], 4);
			else
				*tab = tab[x + 1];
			tab[x] = NULL;
		}
		else
			boo++;
		x++;
	}
	return (boo);
}

int		trim_ver(char **tab)
{
	int		y;
	int		x;
	int 	boo;
	int		dot;
	int		alpha;

	alpha = 0;
	dot = 0;
	x = 0;
	boo = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			tab[y][x] == '.' ? dot++ : alpha++;
			y++;
		}
		if (alpha && alpha + dot == 4)
		{
			alpha = 0;
			dot = 0;
			boo++;
		}
		if (dot == 4)
		{
			y = 0;
			while (y < 4)
			{
				tab[y][x] = 0;
				y++;
			}
		}
		x++;
	}
	return (boo);
}

void	go_left(char **tab, int y, int x)
{
	int		boo = 1;

	while (boo)
	
	{
		x = 0;
		while (x < 4)
		{
			y = 0;
			while (y < 4)
			{
				if (ft_isupper(tab[y][x]) && x == 0)
					return ;
				if (ft_isupper(tab[y][x]) == 1 && x > 0)
				{
					if (tab[y][x - 1] == '.')
					{
						tab[y][x - 1] = tab[y][x];
						tab[y][x] = '.';
						if (x - 1 == 0)
							boo = 0;
					}
					else if (ft_isupper(tab[y][x - 1]))
						boo = 0;
				}
				y++;
			}
			x++;
		}
	}
}

void	go_up(char **tab, int y, int x)
{
	int		boo;

	boo = 1;
	while (boo)
	{
		y = 0;
		while (y < 4)
		{
			x = 0;
			while (x < 4)
			{
				if (ft_isupper(tab[y][x]) && y == 0)
					return ;
				if (ft_isupper(tab[y][x]) == 1 && y > 0)
				{
					if (tab[y - 1][x] == '.')
					{
						tab[y - 1][x] = tab[y][x];
						tab[y][x] = '.';
					}
					if (y - 1 == 0)
						boo = 0;
				}
				x++;
			}
			y++;
		}
	}
}

void	trim_tetris(char **tab)
{
	int		x;
	int		y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (ft_isupper(tab[y][x]) == 1)
			{
				go_left(tab, y ,x);
				go_up(tab, 0, 0);
				return ;
			}
			x++;
		}
		y++;
	}
}

void	put_tetris(t_list **list, t_maillon tetris, char **tab)
{
	static char		n;

	trim_tetris(tab);

	n = 'A';
	tetris.hor = trim_ver(tab);
	tetris.ver = trim_ho(tab, tetris.hor);
	tetris.n_tetris = n;
	n++;

//	printf("TRIM HOR: %i\n", tetris.hor);
//	printf("TRIM VER: %i\n", tetris.ver);

//	printf("TRIIIIIM :\n");
	printf("%s\n", tab[0]);
	printf("%s\n", tab[1]);
	printf("%s\n", tab[2]);
	printf("%s\n\n", tab[3]);

	ft_lstmaillon(&tetris, tetris);
//	printf("___________%s\n", ((t_cote*)((*list)->content))->tab[0]);
} 
