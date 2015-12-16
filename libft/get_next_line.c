/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:27:23 by asalama           #+#    #+#             */
/*   Updated: 2015/12/15 14:30:57 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(int const fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*m = NULL;
	int			ret;

	if ((BUFF_SIZE <= 0) || !line)
		return (-1);
	if (m == NULL)
		m = ft_strnew(0);
	ret = 1;
	while ((ft_strchr(m, '\n') == NULL) && (ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
//		printf("buff = %s\n", buff);
		m = ft_strjoin(m, buff);
//		printf("m = %s\n", m);
	}
	if (ft_strchr(m, '\n'))
		*line = ft_strsub(m, 0, ft_strchr(m, '\n') - m + 1);
	else
		*line = ft_strdup(m);
	if (ret)
		line[0][ft_strlen(*line) - 1] = '\0';
	m = ft_strsub(m, ft_strchr(m, '\n') - m + 1, ft_strlen(ft_strchr(m, '\n')));
	//printf("%d------\n ret = %d\nline = %s\nmem = %s\n-------\n", i, ret, *line, m);
	return (ret == 0 ? 0 : 1);
}

#include <stdio.h>
#include <fcntl.h>

int		main(void)
{
	int		fd;
	char	*line;

	fd = open("test", O_RDONLY);
	//while(get_next_line(fd, &line))
	//	printf("line = [%s]\n", line);
	get_next_line(fd, &line);
	printf("line = [%s]\n", line);
	get_next_line(fd, &line);
	printf("line = [%s]\n", line);
	get_next_line(fd, &line);
	printf("line = [%s]\n", line);
	get_next_line(fd, &line);
	printf("line = [%s]\n", line);
	close(fd);
	return (0);
}

