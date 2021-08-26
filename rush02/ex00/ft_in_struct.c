/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprud-ho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 21:15:30 by mprud-ho          #+#    #+#             */
/*   Updated: 2021/08/22 22:56:21 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

// retourne la string de la valeur alphabetique du nombre
char	*get_string_from_index(char *str, unsigned int start)
{
	unsigned int	len;
	char			*alph_nbr;

	len = 0;
	while (str[start] == ' ' || str[start] == ':')
		start++;
	while (str[start + len] != '\0')
		len++;
	alph_nbr = malloc(sizeof(char) * (len + 1));
	if (alph_nbr == NULL)
		return (NULL);
	len = -1;
	while (str[start + ++len] != '\0')
		alph_nbr[len] = str[start + len];
	alph_nbr[len] = '\0';
	return (alph_nbr);
}

char	*get_number(char *str, unsigned int *len)
{
	unsigned int	i;
	char			*nbr;

	i = 0;
	*len = 0;
	while (str[*len] >= '0' && str[*len] <= '9')
		*len = *len + 1;
	nbr = malloc(sizeof(char) * (*len + 1));
	if (nbr == NULL)
		return (NULL);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr[i] = str[i];
		i++;
	}
	nbr[i] = '\0';
	return (nbr);
}

int	assign_digits(char **lines, t_dictio *dictio)
{
	unsigned int	i;

	i = 0;
	while (lines[i])
	{
		if (lines[i][0] >= '0' && lines[i][0] <= '9'
			&& (lines[i][1] == ':' || lines[i][1] == ' '))
		{
			(*dictio).digit[lines[i][0] - '0']
				= get_string_from_index(lines[i], 2);
			if ((*dictio).digit[lines[i][0] - '0'] == NULL)
				return (-1);
		}
		i++;
	}
	return (0);
}

int	assign_except(char **lines, t_dictio *dictio)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	i = 0;
	j = 0;
	len = 0;
	while (lines[i])
	{
		if (is_exception(lines[i]))
		{
			(*dictio).except[j].nbr = get_number(lines[i], &len);
			if ((*dictio).except[j].nbr == NULL)
				return (-1);
			(*dictio).except[j].str = get_string_from_index(lines[i], len);
			if ((*dictio).except[j].str == NULL)
				return (-1);
			j++;
		}
		i++;
	}
	(*dictio).except[j].nbr = NULL;
	return (0);
}

int	assign_power(char **lines, t_dictio *dictio)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	i = 0;
	j = 0;
	while (lines[i])
	{
		if (is_power(lines[i]))
		{
			len = 0;
			while (lines[i][len] >= '0' && lines[i][len] <= '9')
				len++;
			(*dictio).power[j].n = lines[i][0];
			(*dictio).power[j].len = len;
			(*dictio).power[j].str = get_string_from_index(lines[i], len);
			if ((*dictio).power[j].str == NULL)
				return (-1);
			j++;
		}
		i++;
	}
	(*dictio).power[j].len = 0;
	return (0);
}
