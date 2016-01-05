/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 16:42:28 by asalama           #+#    #+#             */
/*   Updated: 2016/01/05 14:04:09 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fill_with_dots(char **tab, int cote)
{
	int		i;
	int		j;

	j = 0;
	while (j < cote)
	{
		i = 0;
		while (i <cote)
		{
			tab[j][i] = '.';
			i++;
		}
		tab[j][i] = '\0';
		j++;
	}
}

void	print_map(char **map, int cote)
{
	int		i;

	i = 0;
	while (i < cote)
		ft_putendl(map[i++]);
}
