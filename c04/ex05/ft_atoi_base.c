/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 22:44:22 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/13 11:10:33 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			|| base[i] < '!' || base[i] > '~')
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

int	place_in_base(char c, char *base)
{
	unsigned int	i;

	i = 0;
	while (base[i] != c && base[i])
	{
		i++;
	}
	if (base[i] == '\0')
		return (-1);
	else
		return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	i;
	int				nbr;
	int				pos_or_neg;
	unsigned int	base_length;

	i = 0;
	nbr = 0;
	pos_or_neg = 1;
	if (!is_base_valid(base))
		return (0);
	base_length = ft_strlen(base);
	while (str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			pos_or_neg = -pos_or_neg;
	while (str[i] && place_in_base(str[i], base) != -1)
		nbr = nbr * base_length + place_in_base(str[i++], base);
	return (nbr * pos_or_neg);
}

/*
#include<stdio.h>
int	main(int argc, char **argv)
{
	printf("%d", ft_atoi_base(argv[1], argv[2]));
}
*/
