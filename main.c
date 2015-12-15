/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:56:24 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/15 21:21:29 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	fd = open(av[1], O_RDONLY);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		*(buf + ret) = '\0';
		printf("%d", check_tetris(buf));
		char 	**tab;
		tab = (char**)malloc(300);
		*tab = (char*)malloc(300);
		tab = convert(buf);
//		printf("%s\n", tab[0]);
//		printf("%s\n", tab[1]);
//		printf("%s\n", tab[2]);
//		printf("%s\n", tab[3]);
	}
//	ft_error(fd);
	close(fd);
	return (0);
}
