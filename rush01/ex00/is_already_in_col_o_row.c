/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_already_in_col_o_row.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 22:08:16 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/15 23:51:55 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_already_in_col_o_row(int value, int **pg, int coor, int size)
{
	int	i;
	int	x;
	int	y;

	x = coor % size;
	y = coor / size;
	i = 0;
	while (i < size)
	{
		if (pg[x][i] == value || pg[i][y] == value)
			return (1);
		i++;
	}
	return (0);
}
