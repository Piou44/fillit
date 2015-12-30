/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:55:59 by asalama           #+#    #+#             */
/*   Updated: 2015/12/30 18:12:44 by asalama          ###   ########.fr       */
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
	int		cote;

	cote = 0;
	size = nb_tetris * 4;
	while (size > cote * cote)
		cote++;
	return (cote);
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

int		cpy_maillons(char **map, t_list **lst)
{
	int		x;
	int		y;

	j = 0;
	y = 0;
	while (j < 4)
	{
		i = 0;
		x = 0;
		while (i < 4)
		{
			if (ft_isupper((*lst)->((char**)content)[j][i]))
				map[y][x] = (*lst)->((char**)content)[j][i];
			x++;
			i++;
		}
		y++;
		j++;
	
	}
	*lst = (*lst)->next;
	return (0);

}

int		ft_cmp(char **map, t_list **lst, int y, int x)
{
	int		i;
	int		j;
	int		cote;

	j = 0;
	while (y < cote && j < 4)
	{
		x = 0;
		i = 0;
		while (x < cote && ft_isupper(map[y][x]))
			x++;
		while (x < cote && i < 4 && (*lst)->((char**)content)[j][i])
		{ 
			if (ft_isupper((*lst)->((char**)content)[j][i]))
			{
				if (map[y][x] == '.')
					x++;
				else
					return (1);
			}
			else
				x++;
			i++;
		}
		j++;
		y++;
	}
	return (0);
}

char	backtracking(char **map, t_list **lst, int y, int x)
{
	while (ft_cmp(map, lst, y, x) == 0)
	{
		cpy_maillons(map, lst);
	}
	if (ft_cmp(map, lst, y, x) == 1)
		backtracking(map ,lst, y + 1, x);
	return (map);
}














