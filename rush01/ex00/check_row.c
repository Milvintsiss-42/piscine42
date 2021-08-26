/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_row.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 23:49:30 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/15 23:49:49 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int	check_row_r(int **pg, int **limit, int y, int size)
{
	int	i;
	int	pov;
	int	bldings;

	i = 0;
	pov = 0;
	bldings = 0;
	while (i < size)
	{
		if (pg[i][y] > bldings)
		{
			bldings = pg[i][y];
			pov++;
		}
		if (pg[i][y] == 0)
			return (0);
		i++;
	}
	if (limit[2][y] != pov)
		return (-1);
	return (0);
}

int	check_row_l(int **pg, int **limit, int y, int size)
{
	int	i;
	int	pov;
	int	bldings;

	i = size - 1;
	pov = 0;
	bldings = 0;
	while (i >= 0)
	{
		if (pg[i][y] > bldings)
		{
			bldings = pg[i][y];
			pov++;
		}
		if (pg[i][y] == 0)
			return (0);
		i--;
	}
	if (limit[3][y] != pov)
		return (-1);
	return (0);
}

int	check_row(int **pg, int **limit, int y, int size)
{
	if (!check_row_r(pg, limit, y, size)
		&& !check_row_l(pg, limit, y, size))
		return (0);
	return (-1);
}
