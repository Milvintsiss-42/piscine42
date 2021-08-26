/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:40:08 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/24 15:53:34 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void(*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
		(*f)(tab[i++]);
}

/*
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
	ft_foreach(tab, 4, &ft_putint);
}
*/
