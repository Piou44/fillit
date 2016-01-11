/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:55:59 by asalama           #+#    #+#             */
/*   Updated: 2016/01/11 17:11:46 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		backtracking(t_list **lst, int cote)
{
	int				stop;
	char			**grid;
	t_maillon		*tetris;
//	t_maillon		*prev;
	t_list		*tmp;
	stop = 1;
	tmp = *lst;
	while (stop)
	{
		//CREATION tetris (COTE)
		if (!(grid = fresh_map(cote)))
			return (-1);
		print_map(grid, cote);
		sleep(2);
		ft_putchar('\n');
		*lst = tmp;
		while (*lst)
		{
			tetris = ((t_maillon*)((*lst)->content));
			// IF CHEKC PLACE OK -> CPY MAILLON
			if ((try_space(grid, tetris, cote)) == 0)
			{
				ft_putstr("OK\n");
//				prev = *lst;
				*lst = (*lst)->next;
				if (*lst == NULL)
					stop = 0;
				// MAILLON SUIV
				// IF tetris = NULL
				//STOP = 0
			}
			//			else if ((try_space(grid, tetris, cote)) == 2)
			//			{
			//				tetris->y++;
			//				tetris->x = 0;
			//				//if fin :: tetris -> prev
			//			}
			else
			{
				ft_putstr("PAS OK\n");
				tetris->x++;
				if (tetris->x == cote && tetris->y == cote)
				{
//					*lst = prev;
					*lst = find_my_tetris(lst, ((t_maillon*)((*lst)->content))->n_tetris - 1);
					if (*lst == NULL)
						break ;
					ft_erase(grid, tetris->n_tetris, cote);
					tetris->x++;
					//					if (tetris->x >= cote)
					//					{
					//						tetris->x = 0;
					//						tetris->y++;
					///					}
				}
				else if (tetris->x >= cote)
				{
					tetris->x = 0;
					tetris->y++;
				}


				//IF tetris PREV = NULL
				//BREAK 
				//ERASE MAILLON PREV
				//TRY MAILLON PREC EN DECALANT  ->>> SAVE COORD DU MAILLON DAVANT
			}
		}
		if (stop != 0){
		free_map(grid, cote);
		cote++;
		}
		//FREE tetris
		//COTE ++ 
	}
	print_map(grid, cote);
	//PRINT tetris
	return (0);
}














