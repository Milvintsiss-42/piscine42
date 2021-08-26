/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprud-ho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:54:24 by mprud-ho          #+#    #+#             */
/*   Updated: 2021/08/22 21:50:53 by mprud-ho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_valid(char *str)
{
	if (*str == '\0')
		return (1);
	if (*str == '0' && (*(str + 1) == ' ' || *(str + 1) == ':'))
		str++;
	else if (*str < '1' || *str > '9')
		return (0);
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str != ' ' && *str != ':')
		return (0);
	while (*str == ' ')
		str++;
	if (*str != ':')
		return (0);
	str++;
	while (*str == ' ')
		str++;
	if (*str <= 32 || *str >= 127)
		return (0);
	while (*str >= 33 && *str <= 126)
		str++;
	if (*str == '\0')
		return (1);
	return (0);
}

int	nb_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

int	check_doubles(char **lines)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (lines[i])
	{
		if (lines[i][0] == '\0')
			i++;
		j = i + 1;
		while (lines[j])
		{
			if (nb_len(lines[i]) == nb_len(lines[j]))
			{
				k = nb_len(lines[i]);
				if (ft_strncmp(lines[i], lines[j], k) == 0)
				{
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_dictionnary(char **lines)
{
	unsigned int	i;

	i = 0;
	while (lines[i])
	{
		if (ft_valid(lines[i]) == 0 || !check_doubles(lines)
			|| !check_doubles2(lines))
			return (-1);
		i++;
	}
	return (0);
}
