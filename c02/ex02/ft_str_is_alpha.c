/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:26:45 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/09 21:47:43 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int				valid;
	unsigned int	i;
	int				between_a_b;
	int				between_A_B;

	valid = 1;
	i = 0;
	while (str[i] != '\0')
	{
		between_a_b = str[i] >= 'a' && str[i] <= 'z';
		between_A_B = str[i] >= 'A' && str[i] <= 'Z';
		if (!(between_a_b || between_A_B))
			valid = 0;
		i++;
	}
	return (valid);
}
