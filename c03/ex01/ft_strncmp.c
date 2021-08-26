/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:08:19 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/17 23:46:30 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && i < n)
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	if (i < n && s2[i] < 0)
		return (1);
	else if (i < n && s2[i] > 0)
		return (-1);
	return (0);
}

/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int	main(int argc, char **argv)
{
	(void)argc;
	printf("%d\n", ft_strncmp(argv[1], argv[2], atoi(argv[3])));
	printf("%d\n", strncmp(argv[1], argv[2], atoi(argv[3])));
}
*/
