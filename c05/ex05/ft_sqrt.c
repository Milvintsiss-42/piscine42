/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 02:34:10 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/16 03:07:22 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	start;
	int	end;
	int	mid;

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
			start = mid + 1;
		else
			end = mid - 1;
	}
	return (0);
}

/*
#include<stdio.h>
int	main(void)
{
	printf("%d", ft_sqrt(4));//2147395600));
	return (0);
}
*/
