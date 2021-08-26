/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 16:39:48 by mastie            #+#    #+#             */
/*   Updated: 2021/08/16 01:20:06 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "mylib.h"

int	test_in_string(char *arg, int *nb_dec)
{
	int	i;

	i = 0;
	while (arg && (i == 0 || arg[i - 1]))
	{
		if (arg[i] >= '1' && arg[i] <= '9'
			&& (arg[i + 1] == '\0' || arg[i + 1] == ' '))
			*nb_dec = *nb_dec + 1;
		else
			return (ft_putstr_err("Bad string format\n"));
		i += 2;
	}
	if ((*nb_dec % 4) != 0 || *nb_dec < 16)
		return (ft_putstr_err("More or less number are needed\n"));
	return (0);
}

int	**fill_tab(int **limit, char *arg, int size, int i)
{
	int	j;
	int	g;

	g = 0;
	j = 0;
	while (i == 0 || arg[i - 1])
	{
		if (arg[i] - '0' > size)
			return (free_tab(limit, "One of the number is too big"));
		else
		{
			limit[g][j++] = arg[i] - '0';
			if (j == size)
			{
				j = 0;
				g++;
			}
		}
		i += 2;
	}
	return (limit);
}

int	**set_tab_and_value(char *arg, int *nb_dec)
{
	int	**limit;
	int	i;
	int	size;

	i = 0;
	size = *nb_dec / 4;
	limit = (int **)malloc(sizeof(int *) * 4);
	if (limit == NULL)
		return (free_tab(limit, "Malloc failed\n"));
	while (i < size)
	{
		limit[i] = (int *)malloc(sizeof(int) * size);
		if (limit[i] == NULL)
			return (free_tab(limit, "Malloc failed\n"));
		i++;
	}
	return (fill_tab(limit, arg, size, 0));
}

int	main(int argc, char **argv)
{
	int	**limit;
	int	**pg;
	int	nb_dec;

	nb_dec = 0;
	if (argc == 2)
	{
		if (test_in_string(argv[1], &nb_dec) == -1)
			return (-1);
		limit = set_tab_and_value(argv[1], &nb_dec);
		pg = create_the_playground(limit, nb_dec / 4);
		if (solver(pg, limit, 0, nb_dec / 4) == -1)
			return (ft_putstr_err("Not solvable"));
		print_playground(pg, nb_dec / 4);
	}
	else
		return (ft_putstr_err("Wrong number of argument\n"));
	return (0);
}
