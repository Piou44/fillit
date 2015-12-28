/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:55:59 by asalama           #+#    #+#             */
/*   Updated: 2015/12/28 15:29:08 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
unsigned int	ft_sqrt(unsigned int nb)
{
	unsigned int		i;

	i = nb - 1;
	while (nb != i * i)
		--i;
	if (i <= 0)
		return (0);
	return (i);
}

unsigned int	ft_squared(unsigned int nb)
{
	return (nb * nb);
}

char			**smallest_sqr(t_list *lst)
{
}
*/
int				fill_square(t_list *lst)
{
	int		i;
	char	**sqr;

	i = 0;
	sqr = (char**)malloc(sizeof(char*) * 1000);
	while (i < 1000)
		sqr[i] = (char*)malloc(sizeof(char) * 1000);
	return (0);
}
