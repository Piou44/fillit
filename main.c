/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:56:24 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/16 21:16:14 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	char 	**tab;	
	t_list	*list = NULL;

	fd = open(av[1], O_RDONLY);
	char *line;
	do_everything(list, fd, line);
	close(fd);
/*	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		*(buf + ret) = '\0';
		printf("%d\n", check_tetris(buf));
//		tab = (char**)malloc(300);
//		*tab = (char*)malloc(300);
		tab = convert(buf);
		int	y;

	//	for (y = 0; tab[y]; y++)
			printf("%s\n", tab[0]);
			printf("%s\n", tab[1]);
//		get_tetris(&list, tab);
	}
	char	**retour;
	//retour = (char**)malloc(sizeof(char) * 1000);
	//int	i = 0;
	//while (i < 1000)
	//	retour[i++] = (char*)malloc(sizeof(char) * 1000);
	//while (list)
	//{
	//	retour = list->content;
	//	while (*retour)
	//	{
	//		printf("%s\n", *retour);
	//		(*retour)++;
	//	}
	//	printf("%s\n", list->content);
//		ft_putstr(retour[0]);
//		ft_putstr(retour[0]);
//		ft_putstr(retour[0]);
//		printf("%s\n", retour[0]);
//		printf("%s\n", retour[1]);
//		printf("%s\n", retour[2]);
//		printf("%s\n", retour[3]);
//		list = list->next;
//	}
	
//	ft_error(fd);
	if (ac)
	close(fd);
	*/
	return (0);
}
