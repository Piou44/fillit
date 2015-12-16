/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:55:23 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/16 21:16:16 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// CHECK SI TETRIMINOS EST VALIDE

/*
   int		*check_diese(char *buf)
   {
   char	**tab;
   int		**pos;
   int		diese;
   int		i = 0;
   int		j = 0;

   diese = 0;
   if (!(tab = (char**)malloc(BUF_SIZE)))
   return (NULL);
   ft_strcpy(tab, buf);
   while (diese != 4)
   {
   while ()
   if (tab[i] == '#')
   {
   diese++;
 *pos = tab[i][j];
 }
 i++;
 j++;
 }

 }
 */

// CHECK SI TOUT LE BLOC EST VALIDE

int		check_diese(char **tab)
{
	int		x;
	int		y;
	int		diese;
	int		connex;

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
				if (y != 4 && tab[y + 1][x] == '#')
					connex++;
				if (y != 0 && tab[y - 1][x] == '#')
					connex++;
				if (x != 4 && tab[y][x + 1] == '#')
					connex++;
				if (x != 0 && tab[y][x - 1] == '#')
					connex++;
				diese++;
			}
			x++;
		}
		y++;
	}
	return ((connex == 6 || connex == 8) && diese == 4 ? 1 : 0);
}
/*	if (buf[4] == '\n' && buf[9] == '\n' && buf[14] == '\n')
		while (buf[i] && (buf[i] == '.' || buf[i] == '#'))
		{
			if (buf[i] == '.')
				point++;
			if (buf[i] == '#')
				diese++;
			i++;
		}
	if (point == 12 && diese == 4)
		//		if (check_diese(buf))
		return (1);
	return (0);*/


int		do_everything(t_list *lst, int fd, char *line)
{
	int		i;
	int 	j;
	int		gnl;
	char	**tab;

	i = 0;
	j = 0;
	while (1)
	{
		gnl = 0;
		if (!(tab = (char**)malloc(sizeof(char*) * 5)))
			return (0);
		while (gnl++ < 5 && get_next_line(fd, &line))
		{/*
			while (i < ft_strlen(line) + 1)
				if (!(tab[i++] = (char*)malloc(sizeof(char) * ft_strlen(line) + 1)))
					return (NULL);*/
			tab = stock_tab(tab, line);
		}
		if (!(check_tetris(tab)))
		{
	//		free(&tab);
	//		free(*tab);
			return (0);
		}
		put_tetris(&lst, tab);
	}
}
	/*	while (buf[j] != '\0')
	{
		tab[y][x] = buf[j];
		if (buf[j] == '\n')
		{
			y++;
			x = -1;
			buf[j] = '\0';
		}
		j++;
		x++;
	}*/

int		check_tetris(char **tab)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tab[y][x] != '.' || tab[y][x] != '#')
				return (0);
			x++;
		}
		y++;
	}
	return (i == 4 && check_diese(tab) ? 1 : 0);
}

char	**stock_tab(char **tab, char *line)
{
	int				x;
	int				i;
	int				j;
	static int		y;

	x = 0;
	i = 0;
	j = 0;
		tab[y++] = ft_strdup(line);
	return (tab);
/*	while (y < 5)
	{
		x = 0;
		while (x < 5)
		{
			tab[y][x] = buf[j];
			j++;
			x++;
		}
		tab[y][x] = 0;
		j++;
		y++;
	}*/
}
