/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tetris.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 16:57:31 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/09 18:47:53 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	add_tetris(t_maillon **tetris)
{
	t_maillon	*ptr;

	ptr = *tetris;
	if (tetris != NULL && *tetris == NULL)
		*tetris = *tetris;
	else
	{
		while (ptr->next)
		{
			ptr = ptr->next;
		}
		ptr->next = *tetris;
	}
}

void	put_tetris(t_list *lst, t_maillon tetris)
{
	static char		n = 'A';
	char			**tab;

	if (!(lst = (t_list*)malloc(sizeof(t_list))))
		return ;
	lst->next = NULL;
	tab = tetris.tab;
	trim_tetris(tab);
	tetris.hor = trim_ver(tab, -1, -1);
	tetris.ver = trim_ho(tab, tetris.hor);
	tetris.n_tetris = n;
	n++;
	//	printf("TRIM HOR: %i\n", tetris.hor);
	//	printf("TRIM VER: %i\n", tetris.ver);
	//	printf("TRIIIIIM :\n");
	printf("%s\n", tab[0]);
	printf("%s\n", tab[1]);
	printf("%s\n", tab[2]);
	printf("%s\n\n", tab[3]);
	ft_lstaddend(&lst, ft_lstnew(&tetris, sizeof(tetris)));
	//	printf("___________%s\n", ((t_cote*)((*list).content)).tab[0]);
}
