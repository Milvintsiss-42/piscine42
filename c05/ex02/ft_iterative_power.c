/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:56:15 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/17 17:48:17 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	result;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	i = 1;
	result = nb;
	while (i < power)
	{
		result *= nb;
		i++;
	}
	return (result);
}

/*
#include<stdio.h>
int	main(void)
{
	printf("%d", ft_iterative_power(-487, 0));
}
*/
