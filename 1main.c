/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 17:45:08 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/11 17:11:49 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int		main(int ac, char **av)
{
	int			fd;
	int			cote;
	//	char		**grid;
	t_maillon	*tetris;
	t_list		**lst;

	if (ac == 2)
	{
		if (!(tetris = (t_maillon*)malloc(sizeof(t_maillon))))
			return (-1);
		if (!(lst = (t_list**)malloc(sizeof(t_list*))))
			return (-1);
		//		if (!(*lst = (t_list*)malloc(sizeof(t_list))))
		//			return (-1);
		*lst = NULL;
		fd = open(av[1], O_RDONLY);
		if (!(check_file(lst, tetris, fd)))
		{
			ft_putendl("error");
			//			free_tetris(lst);
			close(fd);
			return (0);
		}
		if (*lst == NULL){
			printf("NULL\n");
			return (-1);
		}
		int n = 0;
		n = ft_alphabet('a') - 64;
		printf("NB TETRIS : %i\n", n);
		cote = square_size(n);
		printf("COTE : %i\n", cote);
/*
		while ((*lst)->next)
		{
			*lst = (*lst)->next;
		}
		while ((*lst))
		{
//			printf("STRUCT : %c\n", tetris->n_tetris);
			printf("////%i\n", ((t_maillon*)((*lst)->content))->hor);
			printf("////%i\n", ((t_maillon*)((*lst)->content))->ver);
			printf("////%c\n", ((t_maillon*)((*lst)->content))->n_tetris);
			*lst = (*lst)->prev;
		}
*/

		//		while (backtracking(*lst, cote))
		//		{
		//			printf("DWA\n");
		//			if (!(grid = fresh_map(cote)))
		//				return (-1);
		//			cote++;
		//		}
		//		print_map(grid, cote);
		backtracking(lst, cote);
		return 0;
	}
}
