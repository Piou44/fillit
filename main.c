/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:56:24 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/08 17:31:30 by fhuang           ###   ########.fr       */
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
		tetris = (t_maillon*)malloc(sizeof(t_maillon));
		if (!(do_everything(lst, fd)))
		{
			ft_putstr("error\n"); // MODIF EN UNE FONCTION  + FREE
			close(fd);
			return (-1);
		}
//		ft_putendl("COTE\n");
//		ft_putnbr(cote = square_size(count_tetris(&lst)));
//		ft_putchar('\n');
///		if (!((map = fresh_map(&lst, cote))))
//			return (-1);
		
//		if (lst == NULL){
//			printf("NULL\n");
//			return (0);
//		}
//		ft_putstr("FRESH MAP:\n");
//		print_map(map, cote);
//		backtracking(map, lst, 0, 0, cote);
		//	free (map)
		//	map = fresh_map(lst, ++cote)
//		print_map(map, cote);
//		free(map); // * et **
		close(fd);
	}
	return (0);
}
