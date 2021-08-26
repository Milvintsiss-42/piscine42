/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:07:39 by mastie            #+#    #+#             */
/*   Updated: 2021/08/16 01:19:32 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int	solver(int **pg, int **limit, int coor, int size)
{
	int	x;
	int	y;
	int	i;

	if (coor == size * size)
		return (0);
	x = coor % size;
	y = coor / size;
	if (pg[x][y] != 0)
		return (!solver(pg, limit, coor + 1, size));
	i = 0;
	while (++i <= size)
	{
		if (!is_already_in_col_o_row(i, pg, coor, size))
		{
			pg[x][y] = i;
			if (!check_col(pg, limit, x, size)
				&& !check_row(pg, limit, y, size))
				if (!solver(pg, limit, coor + 1, size))
					return (0);
		}
	}
	pg[x][y] = 0;
	return (-1);
}

int	**create_the_playground(int **limit, int size)
{
	int	**pg;
	int	i;
	int	j;

	i = 0;
	pg = (int **)malloc(sizeof(int *) * size);
	if (pg == NULL)
		return (free_tab(limit, "Malloc failed\n"));
	while (i < size)
	{
		pg[i] = (int *)malloc(sizeof(int) * size);
		if (pg[i] == NULL)
			return (free_tab(limit, "Malloc failed\n"));
		j = 0;
		while (j < size)
			pg[i][j++] = 0;
		i++;
	}
	return (pg);
}

void	print_playground(int **playground, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(playground[j][i] + '0');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
