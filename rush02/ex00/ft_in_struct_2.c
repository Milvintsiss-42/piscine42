/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_struct_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 22:55:37 by jule-mer          #+#    #+#             */
/*   Updated: 2021/08/22 23:00:17 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

// Return -1 if malloc fail, 0 otherwise
int	input_to_dictio(char **lines, t_dictio *dictio)
{
	(*dictio).power = malloc(sizeof(t_power_dictio)
			* (count_powers(lines) + 1));
	(*dictio).except = malloc(sizeof(t_except_dictio)
			* (count_exceptions(lines) + 1));
	(*dictio).digit = malloc(sizeof(char *) * 10);
	if ((*dictio).power == NULL
		|| (*dictio).except == NULL
		|| (*dictio).digit == NULL)
		return (-1);
	if (assign_digits(lines, dictio) == -1
		|| assign_except(lines, dictio) == -1
		|| assign_power(lines, dictio) == -1)
		return (-1);
	return (0);
}
