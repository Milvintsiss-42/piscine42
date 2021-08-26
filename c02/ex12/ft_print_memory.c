/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 23:29:18 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/10 14:15:04 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puthexnbr(unsigned long int nbr, int nb_digit)
{
	char	*hexbase;
	int		i;

	hexbase = "0123456789abcdef";
	i = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
	}
	if (nbr >= 16)
		ft_puthexnbr(nbr / 16, nb_digit - 1);
	else
		while (++i < nb_digit)
			ft_putchar('0');
	ft_putchar(hexbase[nbr % 16]);
}

void	print_hex_values(unsigned char *addr, int i, int limit, int size)
{
	int	to_add;

	to_add = 1;
	while (i < limit && i < size)
	{
		ft_puthexnbr(addr[i], 2);
		if (i % 2 == 1)
			ft_putchar(' ');
		i++;
	}
	if (i == size && size < limit)
	{
		while (i++ < limit)
		{
			if (i % 2 == 1)
				to_add += 2;
			else
				to_add += 3;
		}
		i = 0;
		while (++i < to_add)
			ft_putchar(' ');
	}
}

void	print_characters(unsigned char *addr, int i, int limit, int size)
{
	while (i < limit && i < size)
	{
		if (addr[i] < 32 || addr[i] > 126)
			ft_putchar('.');
		else
			ft_putchar(addr[i]);
		i++;
	}
}

void	ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*char_addr;

	char_addr = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		ft_puthexnbr((unsigned long int)&addr[i], 16);
		write(1, ": ", 2);
		print_hex_values(char_addr, i, i + 16, size);
		print_characters(char_addr, i, i + 16, size);
		ft_putchar('\n');
		i += 16;
	}
}

//int main() {
//	srand(time(NULL));
//	unsigned char	str[50];
//	int i = -1;
//	while (++i < 50)
//		str[i] = rand() % 256;
//	ft_print_memory(str, 49);
//	return 0;
//}
