/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:05:50 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/15 21:15:13 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_alloue_tetris(t_tetris *begin)
{
	t_tetris	*tmp;

	if (!begin)
	{
		begin = (t_tetris*)malloc(sizeof(begin->tetris));
		if (begin == NULL)
			return (-1);
	}
	else
	{
		tmp = (t_tetris*)malloc(sizeof(tmp->tetris) * tmp->nb_tetris);
		if (tmp == NULL)
			return (-1);
	}
	begin->nb_tetris++;
	return (0);
}

int		ft_stock(char *buf)
{
	t_tetris	*ptr;
	char		**map;
	int			i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
			tab[i]
	}
}
