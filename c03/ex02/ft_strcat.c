/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:08:04 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/12 13:23:59 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
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
  printf("%s\n", ft_strcat(dest, src));
  printf("%s\n", strcat(dest2, src));
  return 0;
}
*/
