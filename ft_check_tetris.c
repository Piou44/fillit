/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetris.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 10:57:19 by asalama           #+#    #+#             */
/*   Updated: 2016/01/05 15:47:19 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
				if (y != 3 && tab[y + 1][x] == '#')
					connex++;
				if (y != 0 && tab[y - 1][x] == '#')
					connex++;
				if (x != 3 && tab[y][x + 1] == '#')
					connex++;
				if (x != 0 && tab[y][x - 1] == '#')
					connex++;
				tab[y][x] = ft_alphabet(tab[y][x]);
				diese++;
			}
			x++;
		}
		y++;
	}
	return (((connex == 3) || (connex == 4)) && diese == 4 ? 1 : 0);
}

char		ft_alphabet(char alpha)
{
	static int		i = 1;
	static int		j = 0;
	t_cote		tetris;

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
			tetris.nb_tetris = i;
			j = 0;
		}
	}
	return (alpha);
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

int			free_everything(char **tab, char *line)
{
	int		x;

	x = 0;
	free(line);
	while (x < 4)
		free(tab[x++]);
	free(tab);
	return (0);
}

int			do_everything(t_list **lst, t_cote tetris, int fd)
{
	int			x;
	int			ret;
	char		c;
	char		*line;

	if ((line = (char*)malloc(sizeof(char) * 5)) == NULL)
		return (0);
	ret = 1;
	while ((x = 0) || ret > 0)
	{
		if (!(tetris.tab = (char**)malloc(sizeof(char*) * 4)))
			return (0);
		while (x < 4)
		{
			if ((ret = read(fd, line, 5)) == -1)
				return (0);
			if (line[--ret] == '\n')
				line[ret] = '\0';
			else
				return (0);
			tetris.tab[x++] = ft_strdup(line);
		}
		c = '\0';
		read(fd, &c, 1);
		if (c != '\0' && c != '\n')
			return (0);
		if (!(check_tetris(tetris.tab)))
			return (free_everything(tetris.tab, line));
//		printf("%s\n", tetris.tab[0]);
//		printf("%s\n", tetris.tab[1]);
//		printf("%s\n", tetris.tab[2]);
//		printf("%s\n", tetris.tab[3]);
		put_tetris(lst, tetris, tetris.tab);
		if (c == 0)
			break ;
	}
	free(line);
	return (1);
}
