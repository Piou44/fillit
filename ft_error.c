/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:55:23 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/15 21:48:56 by fhuang           ###   ########.fr       */
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
	printf("LEN :%zu\n", ft_strlen(buf));
//	if (ft_strlen(buf) == 20) { 
	if (buf[4] == '\n' && buf[9] == '\n' && buf[14] == '\n')
	while (buf[i] && (buf[i] == '.' || buf[i] == '#'))
	{
		if (buf[i] == '.')
			point++;
		if (buf[i] == '#')
			diese++;
		i++;
	}
	printf("POINT : %i\n", point);
	printf("DIESE : %i\n", diese);
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
	char	**tab;

	i = 0;
	x = 0;
	y = 0;
	tab = (char**)ft_memalloc(sizeof(char) * 5);
	*tab = (char*)ft_memalloc(sizeof(char) * 5);
	while (buf[i])
	{
	//	tab[x][y] = buf[i];
		i++;
		x++;
		if (buf[i] == '\n')
		{
			y++;
			x = 0;
		}
	}
	return (tab);
}

/*
char	*ft_error(int fd)
{

	int		ret;
	int		i;
	char	buf[BUF_SIZE + 1];

	while ((ret = read(fd, buf, BUF_SIZE)) && buf[i])
	{
		if (ret == -1)
			return ("error\n");
		
	}
	
}*/
