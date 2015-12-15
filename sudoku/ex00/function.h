/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouthie <jrouthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 12:46:45 by jrouthie          #+#    #+#             */
/*   Updated: 2015/07/19 22:29:54 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

void	ft_putchar(char c);
void	ft_printtab(char tab[9][9]);
int		ft_solve(char tab[9][9], int pos, char res[9][9], int *nbs);
int		ft_testcase(char i, char tab[9][9], int x, int y);
int		ft_testzone(char i, char tab[9][9], int x, int y);
int		ft_testline(char i, char tab[9][9], int line);
int		ft_testcol(char i, char tab[9][9], int col);

#endif
