/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:30:04 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/08 17:22:51 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			read_one_c(char *line, int fd)
{
	*line = '\0';
	read(fd, line, 1);
	if (*line != '\0' && *line != '\n')
		return (1);
	return (0);
}
/*
int			good_to_go(t_list **lst, t_maillon tetris, char *line, int ret)
{
	if (!(check_tetris(tetris.tab)))
		return (free_map(tetris.tab, 4));
	put_tetris(lst, tetris, tetris.tab);
	if (*line == '\0' || ret == 0)
		return (0);
	return (1);
}
*/
int			check_file(t_list **lst, t_maillon tetris, int fd)
{
	int			x;
	int			ret;
	char		line[BUF_SIZE + 1];

	while (1)
	{
		if (!(tetris.tab = (char**)malloc(sizeof(char*) * 4)))
			return (0);
		x = 0;
		while (x < 4)
		{
			if ((ret = read(fd, line, BUF_SIZE)) < 0)
				return (0);
			if (line[--ret] == '\n')
				line[ret] = '\0';
			else
				return (0);
			tetris.tab[x++] = ft_strdup(line);
		}
		if ((read_one_c(line, fd)) == 0)
			return (0);
//		if ((good_to_go(lst, tetris, line, ret)) == 1)
//			break ;
//		*line = '\0';
//		read(fd, line, 1);
//		if (*line != '\0' && *line != '\n')
//			return (0);
		if (!(check_tetris(tetris.tab)))
			return (free_map(tetris.tab, 4));
//		put_tetris(lst, tetris);
		if (*line == 0 || ret == 0)
			break ;
	}
	return (1);
}
