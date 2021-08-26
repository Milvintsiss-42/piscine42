/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 19:46:31 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/13 11:03:54 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	unsigned int	i;
	int				nbr;
	int				pos_or_neg;

	i = 0;
	nbr = 0;
	pos_or_neg = 1;
	while (str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			pos_or_neg = -pos_or_neg;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (nbr * pos_or_neg);
}

/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	printf("%d", ft_atoi(argv[1]));
}
*/
