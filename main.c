/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:56:24 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/07 16:45:23 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	int		cote;
	t_list	*lst;
	t_maillon	*tetris;
	char	**map;

	lst = NULL;
	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			return (-1);
//		printf("FD : %i\n", fd);
		ft_putstr("OK\n");
		tetris = (t_maillon*)malloc(sizeof(t_maillon));
		if (!(check_file(&lst, *tetris, fd)))
		{
			ft_putstr("error\n"); // MODIF EN UNE FONCTION  + FREE
			close(fd);
			return (-1);
		}
		ft_putnbr(cote = square_size(4));
		ft_putchar('\n');
		if (!((map = fresh_map(&lst, cote))))
			return (-1);
		
		if (lst == NULL){
			printf("NULL\n");
			return (0);
		}
		ft_putstr("FRESH MAP:\n");
		print_map(map, cote);
//		backtracking(map, lst, 0, 0, cote);
		//	free (map)
		//	map = fresh_map(lst, ++cote)
//		print_map(map, cote);
//		free(map); // * et **
		close(fd);
	}
	return (0);
}
