/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_occ_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 08:49:47 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/22 16:02:31 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_exception(char *str)
{
	unsigned int	i;

	if (str[0] <= '0' || str[0] > '9')
		return (0);
	i = 1;
	while (str[i] == '0')
		i++;
	if (str[i] >= '1' && str[i] <= '9')
		return (1);
	return (0);
}

int	is_power(char *str)
{
	unsigned int	i;

	if (str[0] <= '0' || str[0] > '9')
		return (0);
	i = 1;
	while (str[i] == '0')
		i++;
	if (i >= 2 && (str[i] == ' ' || str[i] == ':'))
		return (1);
	return (0);
}

unsigned int	count_exceptions(char **tab)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		if (is_exception(tab[i]))
			count++;
		i++;
	}
	return (count);
}

unsigned int	count_powers(char **tab)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		if (is_power(tab[i]))
			count++;
		i++;
	}
	return (count);
}

unsigned int	count_digits(char **tab)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		if (tab[i][0] >= '0' && tab[i][0] <= '9'
			&& (tab[i][1] == ':' || tab[i][1] == ' '))
			count++;
		i++;
	}
	return (count);
}
