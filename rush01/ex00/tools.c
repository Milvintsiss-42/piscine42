/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 16:38:07 by mastie            #+#    #+#             */
/*   Updated: 2021/08/15 23:54:05 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "mylib.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		ft_putchar(str[i++]);
}

int	ft_putstr_err(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		ft_putchar(str[i++]);
	return (-1);
}

void	ft_print(int **limit, int size)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < size)
		{
			c = limit[i][j] + 48;
			write(1, &c, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	*free_tab(int **limit, char *str)
{
	int	i;

	i = 3;
	while (i > 0)
	{
		free(limit[i]);
		i--;
	}
	free(limit);
	ft_putstr(str);
	return (NULL);
}
