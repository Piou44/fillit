/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetris.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:25:04 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/31 14:16:28 by fhuang           ###   ########.fr       */
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
	return (0);
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

void	put_tetris(t_list **list, char **tab)//t_fillit *adeter)
{
	char	**trim;
	int		i;
	int		j;
	int		n;

	i = 0;
	j = 0;
	trim = (char**)ft_memalloc(sizeof(char*) * 5);
	while (j < 4)
		trim[j++] = (char*)ft_memalloc(sizeof(char) * 5);
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			trim[j][i] = '.';
			i++;
		}
		trim[j][i] = '\0';
		j++;
	}
	trim_tetris(tab);   // OK EN HAUT A GAUCHE
	
	printf("TRIM : \n");
	printf("%s\n", tab[0]);
	printf("%s\n", tab[1]);
	printf("%s\n", tab[2]);
	printf("%s\n\n\n", tab[3]);
	
	
	n = trim_ver(tab);
	trim_ho(tab, n);
	printf("TRIIIIIM :\n");
	printf("%s\n", tab[0]);
	printf("%s\n", tab[1]);
	printf("%s\n", tab[2]);
	printf("%s\n", tab[3]);
	ft_lstaddend(list, ft_lstnew(trim, sizeof(trim)));//ft_lstnew(adeter, sizeof(adeter)));
	i = 0;
	while (i < 4)
		free(trim[i++]);
	free(trim);
}
