/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 12:02:20 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/09 15:33:29 by fhuang           ###   ########.fr       */
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

char	**fresh_map(int cote)
{
	int		j;
	char	**map;

	if (!(map = (char**)ft_memalloc(sizeof(char*) * (cote + 1))))
		return (NULL);
	j = 0;
	while (j < cote)
		if (!(map[j++] = (char*)ft_memalloc(sizeof(char) * (cote + 1))))
			return (NULL);
	fill_with_dots(map, cote);
	return (map);
}

void	print_map(char **map, int cote)
{
	int		i;

	i = 0;
	while (i < cote)
		ft_putendl(map[i++]);
}
