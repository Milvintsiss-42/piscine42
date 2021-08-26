/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dict2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprud-ho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:45:51 by mprud-ho          #+#    #+#             */
/*   Updated: 2021/08/22 21:43:39 by mprud-ho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_wrddup(char *str, int k)
{
	char	*boom;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != ':')
		i++;
	i++;
	while (str[i] == ' ')
		i++;
	boom = malloc(sizeof(char) * k + 1);
	if (!boom)
		return (NULL);
	while (str[i])
	{
		boom[j] = str[i];
		j++;
		i++;
	}
	boom[j] = '\0';
	return (boom);
}

int	wrd_len(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != ':')
		i++;
	i++;
	while (str[i] == ' ')
		i++;
	while (str[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

int	check_doubles2(char **lines)
{
	int		i;
	int		j;
	char	*tmp;
	char	*tmp2;

	i = -1;
	while (lines[++i])
	{
		if (lines[i][0] == '\0')
			i++;
		j = i;
		while (lines[++j])
		{
			if (wrd_len(lines[i]) == wrd_len(lines[j]))
			{
				tmp2 = ft_wrddup(lines[j], wrd_len(lines[i]));
				tmp = ft_wrddup(lines[i], wrd_len(lines[i]));
				if (ft_strncmp(tmp, tmp2, wrd_len(lines[i])) == 0)
					return (0);
			}
		}
	}
	free(tmp);
	free(tmp2);
	return (1);
}
