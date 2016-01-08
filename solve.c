/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:55:59 by asalama           #+#    #+#             */
/*   Updated: 2016/01/08 19:22:07 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		backtracking(t_maillon *lst, int cote)
{
	int		stop;
	char	**grid;
	t_map	*map;

	stop = 1;
	if (!(map = (t_map*)malloc(sizeof(t_map))))
			return (-1);
	while (stop)
	{
		//CREATION MAP (COTE)
		if (!(grid = fresh_map(cote)))
			return (-1);
		while (lst)
		{
			// IF CHEKC PLACE OK -> CPY MAILLON
				
				// MAILLON SUIV
					// IF LST = NULL
						//STOP = 0
			//ELSE
				//IF LST PREV = NULL
					//BREAK 
				//ERASE MAILLON PREV
				//TRY MAILLON PREC EN DECALANT
		}
		//FREE MAP
		//COTE ++ 
	}
	//PRINT MAP
}














