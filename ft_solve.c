/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:55:59 by asalama           #+#    #+#             */
/*   Updated: 2016/01/06 15:55:47 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			square_size(size_t nb_tetris)
{
	int		size;
	int		cote;

	cote = 0;
	size = nb_tetris * 4;
	while (size > cote * cote)
		cote++;
	return (cote);
}

char		**fresh_map(t_list **lst, int cote)
{
	int			i;
	int			j;
	t_list		*ptr;
	char		**map;

	i = 0;
	ptr = *lst;
	while (ptr)
	{
		ptr = ptr->next;
		i++;
	} 
	if (!(map = (char**)ft_memalloc(sizeof(char*) * (cote + 1))))
		return (NULL);
	j = 0;
	while (j < cote)
		if (!(map[j++] = (char*)ft_memalloc(sizeof(char) * (cote + 1))))
			return (NULL);
	fill_with_dots(map, cote);
	return (map);
}

int		cpy_maillons(char **map, t_list *lst, t_map *coord)
{
	int		x;
	int		y;
	int		i;
	int		j;
	char	**tetris;

	x = coord->x;
	y = coord->y;
	tetris = ((t_cote)(lst->content))->tab;
	j = 0;
	while (y < cote && j < ((t_cote)(lst->content))->ver)
	{
		i = 0;
		while (x < cote && i < ((t_cote)(lst->content))->hor)
		{
			if (ft_isupper(tetris[j][i]) && map[y][x] == '.')
			{
				map[y][x] = tetris[j][i];
				if (ft_isupper(tetris[j][i + 1]))
					map[y][x + 1] = ;
		}
		}
	}
}

int		backtracking(char **map, t_list *lst, int y, int x, int cote)
{
	t_list	*ptr;
	t_map	coord;

	ptr = lst;
	coord.x = 0;
	coord.y = 0;
	coord.cote = cote;
	printf("DEBUT\n");
	if (ptr == NULL)
		return (0);
	printf("WHAT\n");
	while (ft_cmp(map, ptr, y, x, cote, coord) == 0)
	{
		printf("!!!!!!!!!!! YA DE LA PLACE\n");
		cpy_maillons(map, lst, &coord);
		printf("????\n");
		if (backtracking(map, ptr->next, y, x, cote))
			return (0);
	}
//	if (ft_cmp(map, ptr, y, x, cote, coord) == 1)
//	{
//		printf("NO PLACE !!!!!!!!!!!!!! \n");
//		delete_tetris(map);
//		backtracking(map , ptr, y, x + 1, cote);
//	}
	return (0);
}














