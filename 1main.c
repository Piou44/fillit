/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 17:45:08 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/09 19:19:52 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int		main(int ac, char **av)
{
	int			fd;
	int			cote;
	char		**grid;
	t_maillon	*tetris;
	t_list		**lst;

	if (ac == 2)
	{
		if (!(tetris = (t_maillon*)malloc(sizeof(t_maillon))))
			return (-1);
		if (!(lst = (t_list**)malloc(sizeof(t_list*))))
			return (-1);
		if (!(*lst = (t_list*)malloc(sizeof(t_list))))
			return (-1);
			fd = open(av[1], O_RDONLY);
		if (!(check_file(*lst, tetris, fd)))
		{
			ft_putendl("error");
//			free_tetris(&lst);
			close(fd);
			return (0);
		}
		if (lst == NULL || *lst == NULL)
			printf("NULL\n");
//		int		n;

//		printf(">>>\n");
//		n = count_tetris(lst);
//		printf("N :%i\n", n);
		cote = square_size(4);
		printf("COTE : %i\n", cote);
		while (backtracking(*lst, cote))
		{
			printf("DWA\n");
			if (!(grid = fresh_map(cote)))
				return (-1);
			cote++;
		}
		print_map(grid, cote);
		return 0;
	}
}
