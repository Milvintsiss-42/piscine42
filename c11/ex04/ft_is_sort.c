/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:27:41 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/25 03:32:43 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	is_sort;

	is_sort = 1;
	i = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
			is_sort = 0;
		i++;
	}
	if (is_sort == 0)
	{
		i = 0;
		is_sort = 1;
		while (i < length - 1)
		{
			if ((*f)(tab[i], tab[i + 1]) < 0)
				is_sort = 0;
			i++;
		}
	}
	return (is_sort);
}

/*
int diff(int a, int b)
{
	return a - b;
}
#include<libc.h>
int main(int ac, char** av)
{
	int *tab = malloc(sizeof(int) * (ac -  1));
	for (int i = 1; i < ac ; i++)
		tab[i - 1] = atoi(av[i]);
	printf("%d\n", ft_is_sort(tab, ac - 1, &diff ));
}
*/
