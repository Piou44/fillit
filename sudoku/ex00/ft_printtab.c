/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouthie <jrouthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 12:53:32 by jrouthie          #+#    #+#             */
/*   Updated: 2015/07/18 19:57:21 by jrouthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

void	ft_printtab(char tab[9][9])
{
	int x;
	int y;

	x = 0;
	while (x < 9)
	{
		y = 0;
		while (y < 9)
		{
			ft_putchar(tab[x][y]);
			if (y != 8)
				ft_putchar(' ');
			y++;
		}
		ft_putchar('\n');
		x++;
	}
}
