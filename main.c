/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:56:24 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/05 20:50:19 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	int		cote;
	t_list	*lst;
	t_cote	*tetris;
	char	**map;

	lst = NULL;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		printf("OK\n");
		tetris = (t_cote*)malloc(sizeof(t_cote));
		if (!(do_everything(&lst, *tetris, fd)))
		{
			ft_putstr("error\n");
			close(fd);
			return (-1);
		}
		printf("COTE :%i\n", cote = square_size(4));
		if (!((map = fresh_map(&lst, cote))))
			return (-1);
		
		if (lst == NULL){
			printf("NULL\n");
			return (0);
		}
		ft_putstr("FRESH MAP:\n");
		print_map(map, cote);
	backtracking(map, lst, 0, 0, cote);
		//	free (map)
		//	map = fresh_map(lst, ++cote)
		print_map(map, cote);
		free(map); // * et **
		close(fd);
	}
	return (0);
}
