/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:55:04 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/26 01:52:46 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putchar(char c, int channel)
{
	write(1, &c, channel);
}

void	ft_putstr(char *str, int channel)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		write(channel, &str[i++], 1);
}
