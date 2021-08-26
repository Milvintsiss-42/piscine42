/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 03:49:12 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/16 04:08:35 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt_aprox(int nb)
{
	int	start;
	int	end;
	int	mid;
	int	sol;

	if (nb <= 0)
		return (0);
	start = 1;
	end = nb;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (mid * mid == nb)
			return (mid);
		if (mid <= nb / mid)
		{
			start = mid + 1;
			sol = mid;
		}
		else
			end = mid - 1;
	}
	return (sol);
}

int	ft_is_prime(int nb)
{
	int	max_div;
	int	i;

	i = 3;
	max_div = ft_sqrt_aprox(nb);
	while (i <= max_div)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	nb += !(nb % 2);
	while (!ft_is_prime(nb))
		nb += 2;
	return (nb);
}

/*
#include<stdio.h>
int	main(void)
{
	printf("%d\n", ft_find_next_prime(4));
	return (0);
}
*/
