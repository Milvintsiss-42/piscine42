/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:43:15 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/22 23:38:03 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	get_power(char n, int len, t_dictio dictio, int has_space)
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (n != '0' && n != '1')
	{
		while (dictio.power[i].len != 0)
		{
			if (dictio.power[i].len == len && dictio.power[i].n == n)
			{
				ft_putstr(dictio.power[i].str, has_space);
				return ;
			}
			i++;
		}
	}
	i = 0;
	while (dictio.power[i].len != 0)
	{
		if (dictio.power[i].len == len && dictio.power[i].n == '1')
		{
			if (n != '0')
				ft_putstr(dictio.digit[n - '0'], 1);
			ft_putstr(dictio.power[i].str, has_space);
			return ;
		}
		i++;
	}
}	

void	nb0(unsigned int len_nbr, unsigned int i, t_dictio dictio, char *nbr)
{
	if (len_nbr - i != 1 && (len_nbr - i) % 3 == 1
		&& ((i - 1 >= 0 && nbr[i - 1] != '0')
		|| (i - 2 >= 0 && nbr[i - 2] != '0')))
		get_power('0', len_nbr - i, dictio, 1);
}

int	hundred(unsigned int len_nbr, unsigned int i, t_dictio dictio, char *nbr)
{
	unsigned int	j;

	j = 0;
	while (dictio.except[j].nbr != NULL)
	{
		if (ft_strncmp_custom(dictio.except[j].nbr, nbr + i, 3) == 0)
		{
			ft_putstr(dictio.except[j].str, !(i + 2 == len_nbr - 1));
			if (!(i + 2 == len_nbr - 1))
				get_power('0', len_nbr - i - 2, dictio, 1);
			i += 3;
			return (1);
		}
		j++;
	}
	return (0);
}

int ten(unsigned int len_nbr, unsigned int i, t_dictio dictio, char *nbr)
{
	unsigned int	j;

	j = 0;
	while (dictio.except[j].nbr != NULL)
	{
		if (ft_strncmp_custom(dictio.except[j].nbr, nbr + i, 2) == 0)
		{
			ft_putstr(dictio.except[j].str, !(i + 1 == len_nbr - 1));
			if (!(i + 1 == len_nbr - 1))
				get_power('0', len_nbr - i - 1, dictio, 1);
			i += 2;
			return (1);
		}
		j++;
	}
	return (0);
}


void	print(char *nbr, t_dictio dictio)
{
	unsigned int	i;
	unsigned int	len_nbr;

	while (*nbr == '0')
		nbr++;
	len_nbr = ft_strlen(nbr);
	i = -1;
	while (++i < len_nbr)
	{
		if (nbr[i] == '0')
		{
			nb0(len_nbr, i++, dictio, nbr);
			continue ;
		}
		if ((len_nbr - i) % 3 == 0)
		{
			if (hundred(len_nbr, i, dictio, nbr) == 1)
				continue ;
			get_power(nbr[i], 3, dictio, 1);
		}
		else if ((len_nbr - i) % 3 == 2)
		{
			if (ten(len_nbr, i, dictio, nbr) == 1)
				continue ;
			get_power(nbr[i], 2, dictio, 1);
		}
		else if (i == len_nbr - 1)
			ft_putstr(dictio.digit[nbr[i] - '0'], 0);
		else
			get_power(nbr[i], len_nbr - i, dictio, 1);
	}
	write(1, "\n", 1);
}
