/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:55:23 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/16 17:27:06 by fhuang           ###   ########.fr       */
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

int		check_tetris(char *buf)
{
	int		i;
	int		diese;
	int		point;

	i = 0;
	diese = 0;
	point = 0;
	if (buf[4] == '\n' && buf[9] == '\n' && buf[14] == '\n')
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
	return (0);
}

char	**convert(char *buf)
{
	int		x;
	int		y;
	int		i;
	int 	j;
	char	**tab;

	i = 0;
	x = 0;
	y = 0;
	j = 0;
	if (!(tab = (char**)ft_memalloc(sizeof(char*) * 5)))
		return (NULL);
	while (i < 5)
		if (!(tab[i++] = (char*)ft_memalloc(sizeof(char) * 5)))
			return (NULL);
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
	y = 0;
	while (y < 5) {
		x = 0;
		while (x < 5) {
			tab[y][x] = buf[j];
			j++;
			x++;
		}
		tab[y][x] = 0;
		j++;
		y++;
	}
	return (tab);
}
