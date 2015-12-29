/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:55:59 by asalama           #+#    #+#             */
/*   Updated: 2015/12/29 17:56:28 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
unsigned int	ft_sqrt(unsigned int nb)
{
	unsigned int		i;

	i = nb - 1;
	while (nb != i * i)
		--i;
	if (i <= 0)
		return (0);
	return (i);
}*/
/*
unsigned int	ft_squared(unsigned int nb)
{
return (nb * nb);
}
*/

static int			square_size(size_t nb_tetris)
{
	int		size;
	int		sqr;

	sqr = 0;
	size = nb_tetris * 4;
	while (size > sqr * sqr)
		sqr++;
	return (sqr);
}

char		**fresh_map(t_list **lst)
{
	size_t		i;
	size_t		j;
	size_t		size;
	t_list		*ptr;
	char		**map;

	i = 0;
	ptr = *lst;
	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	size = square_size(i);
	if (!(map = (char**)ft_memalloc(sizeof(char*) * (size + 1))))
		return (NULL);
	j = 0;
	while (j < size)
		if (!(map[j++] = (char*)ft_memalloc(sizeof(char) * (size + 1))))
			return (NULL);
	return (map);
}
/*
void		cpy_tetris(char **map, char **tab, int j, int i)
{
	int			x;
	int			y;
	
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (ft_isupper(tab[y][x]) == 0)
				tab[y][x] = map[j][i];
			y++;
			j++;
		}
		x++;
		i++;
	}
}
*/
int		cpy_maillon(t_list **lst)
{
	char	**map;
	int		x;
	int		y;

	j = 0;
	y = 0;
	map = fresh_map(lst);
	while (j < 5)
	{
		i = 0;
		x = 0;
		while (i < 5)
		{
			map[y][x] = (*lst)->((char**)content)[j][i];
			x++;
			j++;
		}
		y++;
		i++;
	}
	return (0);
}

int		cpy_next(t_list **lst, int y, int x)
{
	char	**map;

	map = fresh_map(lst);
	*lst = (*lst)->next;
	j = 0;
	while (j < 5)
	{
		i = 0;
		x = 0;
		while (i < 5)
		{
			map[y][x] = (*lst)->((char**)content)[j][i];
			x++;
			j++;
		}
		y++;
		i++;
	}
	return (0);
}

int		check_space(char **map, t_list **lst)
{
	int		x;
	int		y;

	y = 0;
	while (y < sqr)
	{
		x = 0;
		while (x < sqr)
		{
			if (
			x++;
		}
		y++;
	}

}





















