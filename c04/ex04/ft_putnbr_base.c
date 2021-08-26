/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:52:14 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/13 10:37:34 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	is_base_valid(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-'
			|| base[i] < ' ' || base[i] > '~')
			return (0);
		j = i;
		while (base[++j])
		{
			if (base[i] == base[j])
				return (0);
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	base_length;
	long int		nb;

	if (!is_base_valid(base))
		return ;
	nb = nbr;
	base_length = ft_strlen(base);
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb >= base_length)
		ft_putnbr_base(nb / base_length, base);
	ft_putchar(base[nb % base_length]);
}

/*
#include<stdio.h>
#include<stdlib.h>
int	main(int argc, char **argv)
{
	ft_putnbr_base(atoi(argv[1]), argv[2]);
}
*/
