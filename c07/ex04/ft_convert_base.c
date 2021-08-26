/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:28:03 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/18 18:41:51 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

unsigned int	ft_strlen(char *str);
int				is_base_valid(char *base);
int				place_in_base(char c, char *base);
int				ft_atoi_base(char *str, char *base);

char	*itoa_base_fill(int nbr, char *base, char *a_nbr,
		unsigned int a_nbr_length)
{
	long int		i;
	unsigned int	base_length;
	int				is_negative;

	base_length = ft_strlen(base);
	i = a_nbr_length - 1;
	is_negative = -1;
	if (nbr < 0)
	{
		a_nbr[0] = '-';
		is_negative = 0;
		nbr = -nbr;
	}
	while (i > is_negative)
	{
		a_nbr[i] = base[nbr % base_length];
		nbr /= base_length;
		i--;
	}
	a_nbr[a_nbr_length] = '\0';
	return (a_nbr);
}

char	*itoa_base(int nbr, char *base)
{
	char			*a_nbr;
	unsigned int	base_length;
	unsigned int	a_nbr_length;
	int				temp_nbr;

	base_length = ft_strlen(base);
	a_nbr_length = 0;
	temp_nbr = nbr;
	if (nbr < 0)
	{
		a_nbr_length++;
		temp_nbr = -temp_nbr;
	}
	while (temp_nbr > 0)
	{
		temp_nbr /= base_length;
		a_nbr_length++;
	}
	a_nbr = malloc(sizeof(char) * (a_nbr_length + 1));
	if (a_nbr == NULL)
		return (NULL);
	return (itoa_base_fill(nbr, base, a_nbr, a_nbr_length));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb_in_dec;
	char	*if0;

	if (!nbr || !is_base_valid(base_from) || !is_base_valid(base_to))
		return (NULL);
	nb_in_dec = ft_atoi_base(nbr, base_from);
	if (nb_in_dec == 0)
	{
		if0 = malloc(sizeof(char) * 2);
		if (if0 == NULL)
			return (NULL);
		if0[0] = base_to[0];
		if0[1] = '\0';
		return (if0);
	}
	return (itoa_base(nb_in_dec, base_to));
}

/*
#include<stdio.h>
int	main(int argc, char **argv)
{
	printf("%s\n", ft_convert_base(argv[1], argv[2], argv[3]));
}
*/
