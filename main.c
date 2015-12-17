/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:56:24 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/17 19:12:21 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
//	int		ret;
//	char	buf[BUF_SIZE + 1];
//	char 	**tab;	
	t_list	*list = NULL;

	fd = open(av[1], O_RDONLY);
	char *line = (char*)malloc(sizeof(char) * 300);
	do_everything(list, fd, line);
//	char str[] = "\0";
//	char *ok = NULL;

//	ft_putnbr(last_check(str));	
//	ft_putnbr(last_check(ok));
	if (ac)
	close(fd);
	return (0);
}
