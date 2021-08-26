/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:14:13 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/13 12:25:16 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	facto;
	int	i;

	if (nb < 0)
		return (0);
	facto = 1;
	i = 1;
	while (i <= nb)
	{
		facto *= i;
		i++;
	}
	return (facto);
}

/*
#include <stdio.h>
int main(void)
{
	printf("%d", ft_iterative_factorial(0));
}
*/
