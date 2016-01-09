/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:30:04 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/09 18:52:10 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			read_one_c(char *c, int fd)
{
	*c = '\0';
	read(fd, c, 1);
	if (*c != '\0' && *c != '\n')
		return (0);
	return (1);
}

int			get_fd(t_maillon *adeter, int fd)
{
	int		x;
	int		ret;
	char	line[BUF_SIZE + 1];

	x = 0;
	while (x < 4)
	{
		if ((ret = read(fd, line, 5)) == -1)
			return (0);
		if (line[--ret] == '\n')
			line[ret] = '\0';
		else
			return (0);
		adeter->tab[x++] = ft_strdup(line);
	}
	return (1);
}

int			check_file(t_list *lst, t_maillon *adeter, int fd)
{
	char		c;

	while (1)
	{
		if (!(adeter->tab = (char**)malloc(sizeof(char*) * 4)))
			return (0);
		if (!(get_fd(adeter, fd)))
			return (0);
		if (!(read_one_c(&c, fd)))
			return (0);
		if (!(check_tetris(adeter->tab)))
			return (0);
		put_tetris(lst, *adeter);
		if (c == 0)
			break ;
	}
	return (1);
}
