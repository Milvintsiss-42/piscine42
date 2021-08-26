/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:03:11 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/19 02:52:43 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char			*copy;
	unsigned int	i;

	copy = malloc(sizeof(char) * (ft_strlen(src) + 1));
	i = -1;
	while (src[++i])
		copy[i] = src[i];
	copy[i] = '\0';
	return (copy);
}

/*
#include<stdio.h>
#include<string.h>
int	main(int argc, char **argv)
{
	(void)argc;
	printf("%s\n", ft_strdup(argv[1]));
	printf("%s\n", strdup(argv[1]));	
}
*/
