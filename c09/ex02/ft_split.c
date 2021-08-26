/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:04:25 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/19 14:32:19 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	is_separator(char c, char *seps)
{
	unsigned int	i;

	i = 0;
	while (seps[i])
	{
		if (seps[i] == c)
			return (1);
		i++;
	}
	return (0);
}

unsigned int	ft_strlen_mod(char *str, char *seps)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0' && !is_separator(str[i], seps))
		i++;
	return (i);
}

unsigned int	get_number_of_string(char *str, char *charset)
{
	unsigned int	i;
	unsigned int	nb_of_string;

	i = 0;
	while (is_separator(str[i], charset))
		i++;
	nb_of_string = 0;
	while (str[i])
	{
		if (!is_separator(str[i], charset)
			&& (is_separator(str[i + 1], charset) || str[i + 1] == '\0'))
			 	nb_of_string++;
		i++;
	}
	return (nb_of_string);
}

char	**fill_split(char *str, char *charset, char **split, int i)
{
	unsigned int	j;
	unsigned int	k;

	j = 0;
	while (str[i])
	{
		split[j] = malloc(sizeof(char) * (ft_strlen_mod(str + i, charset) + 1));
		if (split[j] == NULL)
			return (NULL);
		k = 0;
		while (str[i] && !is_separator(str[i], charset))
			split[j][k++] = str[i++];
		split[j][k] = '\0';
		while (is_separator(str[i], charset))
			i++;
		j++;
	}
	split[j] = 0;
	return (split);
}

char	**ft_split(char *str, char *charset)
{
	char			**split;
	unsigned int	i;

	split = malloc(sizeof(char *) * (get_number_of_string(str, charset) + 1));
	if (split == NULL)
		return (NULL);
	i = 0;
	while (is_separator(str[i], charset))
		i++;
	return (fill_split(str, charset, split, i));
}

/*
#include<stdio.h>
int	main(int argc, char **argv)
{
	char			**split;
	unsigned int	i;

	(void)argc;
	split = ft_split(argv[1], argv[2]);
	i = 0;
	while (split[i])
		printf("%s\n", split[i++]);
}
*/
