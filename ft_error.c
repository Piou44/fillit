/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:55:23 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/14 17:08:29 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		*check_diese(char *buf)
{
	char	**tab;
	int		**pos;
	int		diese;

	diese = 0;
	if (!(tab = (char**)malloc(BUF_SIZE)))
		return (NULL);
	ft_strcpy(tab, buf);
	while (diese != 4)
	{
		while ()
		if (tab[i] == '#')
		{
			diese++;
			*pos = tab[i][j];
		}
		i++;
		j++;
	}
	
}

char	*check_tetris(char *buf)
{
	int		i;
	int		diese;
	int		point;

	i = 0;
	diese = 1;
	point = 1;
	if (ft_strlen(buf) == 20)
		if (buf[5] == '\n' && buf[10] == '\n' && buf[15] == '\n' && buf[20] == '\n')
	while (buf[i])
	{
		if (buf[i] == '.')
			point++;
		if (buf[i] == '#')
			diese++;
		i++;
	}
	if (point == 12 || diese == 4)
		if (check_diese(buf))
			return (buf):
	return ("error\n");
}

char	*ft_error(int fd)
{
	int		ret;
	int		i;
	char	buf[BUF_SIZE + 1];

	while (ret = read(fd, buf, BUF_SIZE) && buf[i])
	{
		if (ret == -1)
			return ("error\n");
		
	}
	
}
