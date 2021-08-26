/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprud-ho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 12:39:02 by mprud-ho          #+#    #+#             */
/*   Updated: 2021/08/22 23:10:55 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*hey;
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	hey = malloc(sizeof(char) * (i + j) + 1);
	if (!hey)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
	{
		hey[j] = s1[i];
		j++;
	}
	i = -1;
	while (s2[++i])
	{
		hey[j] = s2[i];
		j++;
	}
	hey[j] = '\0';
	return (hey);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_strncmp_custom(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (ft_strlen(s1) != n)
		return (-1);
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
