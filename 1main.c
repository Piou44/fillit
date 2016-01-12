/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 17:45:08 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/12 19:36:59 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int		main(int ac, char **av)
{
	int			fd;
	int			cote;
	t_maillon	*tetris;
	t_list		**lst;

	if (ac == 2)
	{
		if (!(tetris = (t_maillon*)malloc(sizeof(t_maillon))))
			return (-1);
		if (!(lst = (t_list**)malloc(sizeof(t_list*))))
			return (-1);
		*lst = NULL;
		fd = open(av[1], O_RDONLY);
		if (!(check_file(lst, tetris, fd)))
		{
			ft_putendl("error");
			//			free_tetris(lst);
			close(fd);
			return (0);
		}
		int n = 0;
		n = ft_alphabet('a') - 64;
		cote = square_size(n);
		backtracking(lst, cote);
		return 0;
	}
}
