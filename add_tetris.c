/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tetris.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 16:57:31 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/11 16:48:32 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	put_tetris(t_list **lst, t_maillon tetris)
{
	char	c;

	trim_tetris(tetris.tab);
	tetris.hor = trim_ver(tetris.tab, -1, -1);
	tetris.ver = trim_ho(tetris.tab, tetris.hor);
	c = ft_alphabet('a');
	tetris.n_tetris = c;
	tetris.x = 0;
	tetris.y = 0;
	printf("HOR :%i\n", tetris.hor);
	printf("VER :%i\n", tetris.ver);
	printf("N :%c\n", tetris.n_tetris);
	
	printf("%s\n", tetris.tab[0]);
	printf("%s\n", tetris.tab[1]);
	printf("%s\n", tetris.tab[2]);
	printf("%s\n\n", tetris.tab[3]);
	
	
	
	
	
	ft_lstaddend(lst, ft_lstnew(&tetris, sizeof(tetris)));
}
