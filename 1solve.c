/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:55:59 by asalama           #+#    #+#             */
/*   Updated: 2016/01/09 19:23:05 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"



int		backtracking(t_list *lst, int cote)
{
	char		**grid;
	t_maillon	*tetris;

	tetris = ((t_maillon*)(lst->content));
	if (!tetris)
		return (0);
	if (!(grid = fresh_map(cote)))
		return (-1);
	//CREATION tetris (COTE)
	// IF CHEKC PLACE OK -> CPY MAILLON
	if (!(try_space(grid, tetris, cote)))
	{
		tetris = tetris->next;
		if (!(backtracking(lst, cote)))
			return (0);
		ft_erase(grid, tetris->n_tetris, cote);
		tetris->x++;
		if (tetris->x == cote)
		{
			tetris->x = 0;
			tetris->y++;
		}
		if (!(backtracking(lst, cote)))
			return (0);
		else
			return (1);
		// MAILLON SUIV
		// IF tetris = NULL
		//STOP = 0
	}
	else
	{
		tetris->x++;
		if (tetris->x == cote && tetris->y == cote && tetris->n_tetris == 'A')
			return (1);
		if (tetris->x == cote)
		{
			tetris->x = 0;
			tetris->y++;
		}
	}
	//IF tetris PREV = NULL
	//BREAK 
	//ERASE MAILLON PREV
	//TRY MAILLON PREC EN DECALANT  ->>> SAVE COORD DU MAILLON DAVANT

	free_map(grid, cote);
	//FREE tetris
	//COTE ++ 
	return (1);
}














