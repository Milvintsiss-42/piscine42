/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:19:50 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/19 01:32:34 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
int	*ft_range(int min, int max)
{
	int	i;
	int	size;
	int	*range;

	if (min >= max)
		return (0);
	size = max - min;
	range = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}

/*
#include <stdio.h>
int	main(void)
{
	int	tab[3];
	int	i;

	tab = ft_range(5, 8);
	i = 0;
	while (i < 3)
	{
		printf("%i\n", tab[i]);
		i++;
	}
}
*/
