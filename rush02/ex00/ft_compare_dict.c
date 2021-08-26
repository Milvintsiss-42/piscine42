/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare_dict.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 17:13:29 by jule-mer          #+#    #+#             */
/*   Updated: 2021/08/22 19:57:45 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strcmp_nbr(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] >= '0' && s1[i] <= '9' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_compare_dict(char **lines, char **check)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (check[++i])
	{
		j = -1;
		k = 0;
		while (lines[++j] && k == 0)
		{
			if (ft_strcmp_nbr(check[i], lines[j]) == 0)
				k = 1;
		}
		if (k == 0)
			return (-5);
	}
	return (0);
}
