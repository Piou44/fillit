/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:42:01 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/08 11:58:38 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int			count_tetris(t_list **lst)
{
	int		n;

	n = 0;
	while (*lst)
	{
		*lst = (*lst)->next;
		n++;
	}
	return (n);
}

int			square_size(size_t nb_tetris)
{
	int		size;
	int		cote;

	cote = 0;
	size = nb_tetris * 4;
	while (size > cote * cote)
		cote++;
	return (cote);
}
