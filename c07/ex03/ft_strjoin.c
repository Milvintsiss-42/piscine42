/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 21:49:08 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/19 19:04:48 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

unsigned long int	ft_strlen(char *str)
{
	unsigned long int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strcat(char *dest, char *src, unsigned int start)
{
	unsigned long int	i;

	i = 0;
	while (src[i])
	{
		dest[i + start] = src[i];
		i++;
	}
	return (start + i);
}

unsigned long int	get_length(int size, char **strs, char *sep)
{
	unsigned long int	length;
	int					i;

	i = 0;
	length = 0;
	while (i < size)
	{
		length += ft_strlen(strs[i]);
		if (i++ != size - 1)
			length += ft_strlen(sep);
	}
	return (length);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char				*joined_str;
	unsigned long int	length;
	int					i;
	unsigned int		start;

	if (size == 0)
	{
		joined_str = malloc(sizeof(char));
		*joined_str = '\0';
		return (joined_str);
	}
	length = get_length(size, strs, sep);
	joined_str = malloc(sizeof(char) * (length + 1));
	if (joined_str == NULL)
		return (NULL);
	i = 0;
	start = 0;
	while (i < size)
	{
		start = ft_strcat(joined_str, strs[i], start);
		if (i++ != size - 1)
			start = ft_strcat(joined_str, sep, start);
	}
	joined_str[length] = '\0';
	return (joined_str);
}

/*
#include<stdio.h>
int	main(int argc, char **argv)
{
	printf("%s\n", ft_strjoin(argc - 2, argv + 2, argv[1]));
}
*/
