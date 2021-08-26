/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 23:01:30 by jule-mer          #+#    #+#             */
/*   Updated: 2021/08/22 23:39:31 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_which_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	i--;
	if (i == 1)
		return (1);
	if (i == 2)
	{
		if (str[i] >= '1' && str[i] <= '9')
			return (2);
		if (str[i] == '0')
			return (3);
	}
	if (i > 2)
	{
		if (str[i] == '0')
			return (3);
	}
	return (4);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str, int b_has_space)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	if (b_has_space == 1)
		write(1, " ", 1);
}

int	ft_srch(char *str, char c)
{
	int	i;

	i = 0;
	while (i < 9 || str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
