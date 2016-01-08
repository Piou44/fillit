/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 17:45:08 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/08 18:03:49 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	t_list	*lst;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (!(do_everything(lst, fd)))
		{
			ft_putendl("error");
			close(fd);
			return (0);
		}
		return 0;
	}
}
