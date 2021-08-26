/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:27:19 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/21 01:38:24 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include"ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long int	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar((nbr % 10) + '0');
}

void	ft_putstr_n(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par->str != 0)
	{
		ft_putstr_n(par->str);
		ft_putnbr(par->size);
		write(1, "\n", 1);
		ft_putstr_n(par->copy);
		par++;
	}
}
