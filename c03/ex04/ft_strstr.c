/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 14:56:28 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/12 15:50:43 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] && str[i + j] == to_find[j])
		{
			j++;
			if (to_find[j] == '\0')
				return (str + i);
		}
		i++;
	}
	return (0);
}

/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char** argv) {
  char str[] = "abcdefghi";
  printf("%s\n", ft_strstr(str, argv[1]));
  printf("%s\n", strstr(str, argv[1]));
  return 0;
}
*/
