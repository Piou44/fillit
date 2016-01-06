/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */

/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 12:09:41 by asalama           #+#    #+#             */
/*   Updated: 2016/01/06 14:54:36 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_init_coord(t_map map_coord, t_map *sub)
{
	map_coord.x = 0;
	map_coord.y = 0;
	map_coord.cote = sub->cote;
}

int		ft_verif_coord(t_map *map_coord, t_map *sub)
{
	int		x;
	int		y;
	int		retx;
	int		rety;

	x = map_coord->x;
	y = map_coord->y;
	if ((retx = (x + sub->x)) < 0)
		return (1);
	else if (retx > sub->cote)
		return (2);
	if ((rety = (y + sub->y)) < 0)
		return (3);
	else if (rety > sub->cote)
		return (-1);
	return (0);
}

int		ft_add(char **map, t_maillon *tetris, t_map *sub)
{
	static t_map	*map_coord = NULL;
	int				ret;
	if (map_coord == NULL)
		ft_init_coord(*map_coord, sub);
	if ((ret = ft_verif_coord(map_coord, sub)) == 0)
	while (map_coord->y < map_coord->cote)
	{
		while (map_coord->x < map_coord->cote)
		{
			if (map[map_coord->y][map_coord->x] == '.')
			{
				if (map[map_coord->y + sub->y][map_coord->x + sub-> x] == '.')
					return (0);
				else if (map_coord-> x < cote)
					map_coord->x++;
					return (1);
			}
			map_coord->x++;
		}
		if (map_coord->x == map_coord->cote)
			map_coord->x = 0;
		map_coord->y++;
	}
	else if (ret == 1)
		map_coord->x++;
	else if (ret == 2)
	{
		map_coord->y++;
		map_coord.x = 0;
	}
	else if (ret == 3)
		map_coord->y++;
	else
		return (1);
}

int		ft_sub(char **map, t_maillon *tetris, t_map *save_coord)
{
	int		i;
	int		j;
	t_map	sub;

	j = (save_coord->y) + 1;
	while (j < tetris->ver)
	{
		i = (save_coord->x) + 1;
		while (i < tetris->hor)
		{
			if (ft_isupper(tetris->tab[j][i]))
			{
				sub.x = i - save_coord->x;
				sub.y = j - save_coord->y;
				sub.cote = save_coord->cote;
				ft_add(map, tetris, &sub);
			}
			i++;
		}
		if (i == tetris->hor)
			i = 0;
		j++;
	}
}


int		ft_cmp(char **map, t_list *lst)
{
	// SAUV COORD DE 1ere LETTRE
	// SOUSTRAIRE AVEC COORD DES DIESES SUIV
	// DANS MAP :: SI ON EST A UN POINT , ADDITIONNER AVEC COORD DE TTALHEURE -> REGARDER SI YA UN POINT
	


	//

	t_maillon		tetris;
	t_map			save_coord;
	int				i;
	int				j;

	tetris.tab = ((t_maillon*)(lst->content))->tab;
	tetris.hor = ((t_maillon*)(lst->content))->hor;
	tetris.ver = ((t_maillon*)(lst->content))->ver;

	j = 0;
	while (j < tetris.ver)
	{
		i = 0;
		while (i < tetris.hor)
		{
			if (ft_isupper(tetris.tab[j][i]))
			{
				save_coord.x = i;
				save_coord.y = j;
				ft_sub(map, &tetris, &save_coord);
			}
			i++;
		}
		j++;
	}
}
