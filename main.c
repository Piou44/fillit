/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:56:24 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/31 14:18:22 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
//	int		cote;
	t_list	*list;
//	char	**map;

	list = NULL;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (!(do_everything(list, fd)))
		{
			ft_putstr("error\n");
			close(fd);
			return (-1);
		}
//		cote = sqaure_size();
//		if (!(map = fresh_map(lst, size)))
//			return (-1);
//		backtrack;
//		print_map(map);
//		free(map); // * et **
		close(fd);
	}
	return (0);
}
