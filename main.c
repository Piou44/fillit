/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:56:24 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/22 18:00:04 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	t_list	*list = NULL;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (!(do_everything(list, fd)))
		{
			ft_putstr("error\n");
			close(fd);
			return (0);
		}
		close(fd);
	}
	return (0);
}
