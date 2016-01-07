/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 16:42:28 by asalama           #+#    #+#             */
/*   Updated: 2016/01/07 15:22:20 by fhuang           ###   ########.fr       */
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

char	**fresh_map(t_list **lst, int cote)
{
	int		j;
	t_list	*ptr;
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
