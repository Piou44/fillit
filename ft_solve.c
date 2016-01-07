/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:55:59 by asalama           #+#    #+#             */
/*   Updated: 2016/01/07 17:35:16 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		backtracking(char **map, t_list *lst, int y, int x, int cote)
{
	t_list	*ptr;
	t_map	coord;

	ptr = lst;
	coord.x = 0;
	coord.y = 0;
	coord.cote = cote;
	if (ptr == NULL)
		return (0);
	while (ft_cmp(map, ptr, y, x, cote, coord) == 0)
	{
		cpy_maillons(map, lst, &coord);
		if (backtracking(map, ptr->next, y, x, cote))
			return (0);
	}
//	if (ft_cmp(map, ptr, y, x, cote, coord) == 1)
//	{
//		printf("NO PLACE !!!!!!!!!!!!!! \n");
//		ft_erase(map, lst->prev, cote);
//		backtracking(map , ptr, y, x + 1, cote);
//	}
	return (0);
}














