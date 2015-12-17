/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:55:23 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/17 19:12:17 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

typedef	struct	 s_fillit
{
	int		diese;
	char	**tab;
}				t_fillit;

int		check_diese(char **tab, int diese)
{
	int		x;
	int		y;
	int		connex;

	y = 0;
	connex = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tab[y][x] == '#')
			{
			if (y != 3 && tab[y + 1][x] == '#')
					connex++;
				if (y != 0 && tab[y - 1][x] == '#')
					connex++;
				if (x != 3 && tab[y][x + 1] == '#')
					connex++;
				if (x != 0 && tab[y][x - 1] == '#')
					connex++;
				diese++;
				tab[y][x] = ft_alphabet(tab[y][x]);
//				printf("alpha: %c\n", tab[y][x]);	
			}
			x++;
		}
		y++;
	}
//	printf("connex : %i\n", connex);
//	printf("diese: %i\n", diese);
	return ((connex == 6 || connex == 8) && diese == 4 ? 1 : 0);
}

char		ft_alphabet(char alpha)
{
	static int		i = 0;
	static int		j = 0;
	
	if (alpha == '#') {
	if (j <= 4)
	{
		alpha = i + 65;
//		printf("AL: %c\n", alpha);
		j++;
	}
	if (j == 4)
	{
		i++;
		j = 0;
	}}
	return (alpha);
}

int		do_everything(t_list *lst, int fd, char *line)
{
	int		i;
	int 	j;
	int		x;
	int		ret =  1;
	int		gnl;
	t_fillit adeter;



	i = 0;
	j = 0;
	while (ret > 0)
	{
		gnl = 0;
		if (!(adeter.tab = (char**)malloc(sizeof(char*) * 300)))
			return (0);
		x = 0;
		while (gnl++ < 5 && (ret = get_next_line(fd, &line)))
		{
			adeter.tab[x++] = ft_strdup(line);
		}
//		printf("check_col : %i\n", check_col(adeter.tab));
//		printf("check_line : %i\n", check_line(adeter.tab, line));
//		printf("check_diese : %i\n", check_diese(adeter.tab, adeter.diese));
		printf("check tetris :%i\n", check_tetris(adeter.tab, adeter.diese));
//		if (!(check_tetris(adeter.tab, line, adeter.diese)))
//		{
	//		free(&tab);
	//		free(*tab);
//			return (0);
//		}
		put_tetris(&lst, adeter.tab);
	}
	return (1);
}

int		last_check(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '#')
		   return (0);	
		i++;
	}
	return (1);
}

int		check_line(char **tab)
{
	int		x = 0;
	
	while (x < 4)
	{
		if (last_check(tab[x]) == 0 || ft_strlen(tab[x]) != 4)
			return (0);
		x++;
	}
	return (check_col(tab) == 4 ? 1 : 0);
}

int		check_col(char **tab)
{
	int		x;

	x = 0;
	while (*tab[x] != '\0')
		x++;
	return (x);
}

int		check_tetris(char **tab, int diese)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
//			if (tab[y][x] != '.' && tab[y][x] != '#')
//				return (0);
			x++;
		}
		y++;
	}
	return ((check_line(tab) && check_diese(tab, diese)) ? 1 : 0);
}
