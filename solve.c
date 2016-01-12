/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:55:59 by asalama           #+#    #+#             */
/*   Updated: 2016/01/12 19:38:58 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

# define CONTENT ((t_maillon*)((*lst)->content))

int		backtracking(t_list **lst, int cote)
{
	int				stop;
	char			**grid;
	t_list			*first_m;

	stop = 1;
	first_m = *lst;
	while (stop)
	{
		if (!(grid = fresh_map(cote)))
			return (-1);
		//		*lst = first_m;
		while (*lst)
		{
			if ((try_space(grid, CONTENT, cote)) == 0)
			{
				*lst = (*lst)->next;
				if (*lst == NULL)
					stop = 0;
			}
			else
			{
				if (CONTENT->x == cote - 1 && CONTENT->y == cote - 1)
				{
					coord_maillon(*lst);
					*lst = find_my_tetris(lst, first_m, CONTENT->n_tetris - 1);

					if (*lst == NULL)
						break ;
					ft_erase(grid, CONTENT->n_tetris, cote);
				}
				if (CONTENT->x >= cote)
				{
					CONTENT->x = 0;
					CONTENT->y++;
				}
				else
					CONTENT->x++;
			}
		}
		if (stop != 0)
		{
			free_map(grid, cote);
			cote++;
			*lst = first_m;
			coord_list(lst, first_m);
		}
	}
	print_map(grid, cote);
	return (0);
}














