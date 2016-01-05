/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:55:59 by asalama           #+#    #+#             */
/*   Updated: 2016/01/05 20:50:12 by asalama          ###   ########.fr       */
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
					map[y][x + 1] = 
		}
		/*	
	j = 0;
	y = 0;
	while (j < 4)
	{
		i = 0;
		x = 0;
		while (i < 4)
		{
			
			if (ft_isupper((((char**)(lst->content)))[j][i]))
				map[y][x] = ((char**)(lst->content))[j][i];
			x++;
			i++;
		}
		y++;
		j++;


	}
	lst = lst->next;
	return (0);
*/
/*	j = 0;
	tetris = ((t_cote)(lst->content))->tab;
	x = coord->x;
	y = coord->y;
	while (y < cote && j < ((t_cote)(lst->content))->ver)
	{
		i = 0;
		while (x < cote && i < ((t_cote)(lst->content))->hor)
		{
			while (ft_isupper(map[y][x]))
				x++;
			if (ft_isupper(tetris[j][i]))
			{
				map[y][x] = tetris[j][i];
				x++;
			
				}
			i++;
		}
		j++;
		y++;
	}
}
*/

int		ft_map_check(char **map, int cote)
{
	int		x;
	int		y;
	
	y = 0;
	while (y < cote)
	{
		x = 0;
		while (x < cote)
		{
			if (ft_isupper(map[y][x]))
				x++;
			if (x == cote)
			{
				y++;
				x = 0;
			}

		}
	}
}



int		ft_check_place(t_list *lst, char **map)
{
	char	**tetris;
	int		i;
	int		j;
	int		ver;
	int		hor;
	t_map	coord;

	tetris = ((t_cote*)(lst->content))->tab;
	ver = ((t_cote*)(lst->content))->ver;
	hor = ((t_cote*)(lst->content))->hor;
	j = 0;
	while (j < ver)
	{
		i = 0;
		while (i < hor)
		{
			if (ft_isupper(tetris[j][i]))
			{
				coord.x = i;
				coord.y = j;
				ft_finish(lst, &coord, map);
			}
			i++;
		}
	}
}

int		ft_finish(t_list *lst, t_map *coord, char **map)
{
	int		i;
	int		j;
	int		ver;
	int		hor;
	t_map	formula;
	char	**tetris;
	
	tetris = ((t_cote*)(lst->content))->tab;
	ver = ((t_cote*)(lst->content))->ver;
	hor = ((t_cote*)(lst->content))->hor;
	j = 0;
	while (j < ver)
	{
		i = 0;
		while (i < hor)
		{
			if (ft_isupper(tetris[j][i]))
			{
				formula.x = i - coord->x;
				formula.y = j - coord->y;
			}
			i++;
		}
}

int		ft_finish2(t_list *lst, t_map *coord, t_map *formula char **map)
{
	static int	

	

int		ft_cmp(char **map, t_list *lst, int y, int x, int cote, t_map coord)
{
	char	**tetris;
	int		hor;
	int		ver;
	int		i;
	int		j;

	tetris = (((t_cote*)(lst->content))->tab);
	/*
	int		i;
	int		j;
	int		ver;
	int		hor;
	char	**tetris;

	tetris = (((t_cote*)(lst->content))->tab);
	ver = (((t_cote*)(lst->content))->ver);
	hor = (((t_cote*)(lst->content))->hor);
	printf("HOR :%i\n", hor);
	printf("VER :%i\n", ver);
	j = 0;
	while (y < cote && x < cote && ft_isupper(map[y][x]))
	{
		x++;
		if (x == cote && (y++))
			x = 0;
		printf("NON\n");
	}
	i = 0;
	while (j < ver && i < hor && tetris[j][i] == '.')
	{
		i++;
		if (i == hor)
		{
			i = 0;
			j++;
		}
		printf("UNE FOIS\n");
	}
	if (ft_isupper(tetris[j][i]))
	{
		while (j < ver && y < hor)
		{
//			printf("BOUCLE\n");
			while (y < cote && j < ver && i < hor && x < cote && map[y][x] == '.')
			{
				i++;
				x++;
				if (i == hor){
					i = 0;
					j++;
				}
				if (x == cote)
				{	
					x = 0;
					y++;
				}
			}
			if (ft_isupper(map[y][x])){
				printf("RETURN\n");
				return (1);
			}
		}
	}
	coord.y = y;
	coord.x = x;*/
	return (0);
}

int		backtracking(char **map, t_list *lst, int y, int x, int cote)
{
	t_list	*ptr;
	t_map	coord;

	ptr = lst;
	coord.x = 0;
	coord.y = 0;
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














