/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:08:04 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/12 14:55:34 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j] && j < nb)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
  char src[] = "abcde";
  char dest[100] = "str=";
  char dest2[100] = "str=";
  printf("%s\n", ft_strncat(dest, src, 7));
  printf("%s\n", strncat(dest2, src, 7));
  return 0;
}
*/
