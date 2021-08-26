/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:55:06 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/24 23:25:17 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*cp_tab;

	cp_tab = malloc(sizeof(int) * length);
	if (cp_tab == NULL)
		return (NULL);
	i = -1;
	while (++i < length)
		cp_tab[i] = (*f)(tab[i]);
	return (cp_tab);
}
/*
int	add(int nb) 
{
	return (nb + 1);
}

#include<unistd.h>
void ft_putint(int nb)
{
	char c;
	c = (char)nb;
	write(1, &c, 1);
}

int	main(void)
{
	int tab[] = {65, 66, 67, 68};
	int	i;
	
	i = 0;
	ft_map(tab, 4, &add);
	while (i < 4)
		ft_putint(tab[i++]);
}
*/
