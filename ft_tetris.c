/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetris.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:25:04 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/29 17:56:32 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

void	start(char **tab, char **trim, int y, int x)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (ft_isupper(tab[y][x]) == 1)
			{
				if (ft_isupper(tab[y - 1][x + 1]) && tab[y - 1][x] == '.')
				{
					j++;
					if (ft_isupper(tab[y - 2][x + 1]) == 1)
						j++;
				}
				else if (ft_isupper(tab[y - 1][x - 2]) == 1 && tab[y - 1][x] == '.')
					j++;
				trim[j][i] = tab[y][x];
			}
			x++;
			i++;
		}
		y++;
		j++;
	}
}

void	trim_tetris(char **tab, char **trim)
{
	int		x;
	int		y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (ft_isupper(tab[y][x]) == 1)
			{
				start(tab, trim, y ,x);
				return ;
			}
			x++;
		}
		y++;
	}
}

void	put_tetris(t_list **list, char **tab)//t_fillit *adeter)
{
	char	**trim;
	int		i;

	i = 0;
	j = 0;
	trim = (char**)ft_memalloc(sizeof(char*) * 5);
	while (i < 5)
		trim[i++] = (char*)ft_memalloc(sizeof(char) * 5);
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			trim[j][i] == '.';
			j++;
		}
		trim[j][i] = '\0';
		i++;
	}
	trim_tetris(tab, trim);
	
	ft_lstaddend(list, ft_lstnew(trim, sizeof(trim)));//ft_lstnew(adeter, sizeof(adeter)));
	i = 0;
	while (i < 5)
		free(trim[i++]);
	free(trim);
}
