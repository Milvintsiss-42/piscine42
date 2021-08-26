/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 22:36:15 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/16 00:44:15 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int	check_col_u(int **pg, int **limit, int x, int size)
{
	int	i;
	int	pov;
	int	bldings;

	i = 0;
	pov = 0;
	bldings = 0;
	while (i < size)
	{
		if (pg[x][i] > bldings)
		{
			bldings = pg[x][i];
			pov++;
		}
		if (pg[x][i] == 0)
			return (0);
		i++;
	}
	if (limit[0][x] != pov)
		return (-1);
	return (0);
}

int	check_col_d(int **pg, int **limit, int x, int size)
{
	int	i;
	int	pov;
	int	bldings;

	i = size - 1;
	pov = 0;
	bldings = 0;
	while (i >= 0)
	{
		if (pg[x][i] > bldings)
		{
			bldings = pg[x][i];
			pov++;
		}
		if (pg[x][i] == 0)
			return (0);
		i--;
	}
	if (limit[1][x] != pov)
		return (-1);
	return (0);
}

int	check_col(int **pg, int **limit, int x, int size)
{
	if (!check_col_u(pg, limit, x, size)
		&& !check_col_d(pg, limit, x, size))
		return (0);
	return (-1);
}
