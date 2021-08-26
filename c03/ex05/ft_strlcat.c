/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:51:25 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/17 20:27:34 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	str_length(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int	size)
{
	unsigned int	i;
	unsigned int	length_dest;
	unsigned int	length_src;

	length_dest = str_length(dest);
	length_src = str_length(src);
	if (length_dest >= size)
	{
		return (length_src + size);
	}	
	i = 0;
	while (i < size - length_dest && src[i])
	{
		dest[i + length_dest] = src[i];
		i++;
	}
	if (i + length_dest < size)
		dest[i + length_dest] = '\0';
	else
		dest[i + length_dest - 1] = '\0';
	return (length_dest + length_src);
}

/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int	main(int argc, char **argv)
{
	char *dest1 = strdup(argv[1]);
	char *dest2 = strdup(argv[1]);
	printf("%lu\n", strlcat(dest1, argv[2], atoi(argv[3])));
	printf("%s\n\n", dest1);

	printf("%u\n", ft_strlcat(dest2, argv[2], atoi(argv[3])));
	printf("%s\n", dest2);
	return (0);
}
*/
