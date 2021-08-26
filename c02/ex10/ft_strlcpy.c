/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 18:22:02 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/10 21:46:25 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len])
	{
		if (size != 0 && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		src_len++;
	}
	while (i < size)
	{
		dest[i] = 0;
		i++;
	}
	return (src_len);
}
//#include <stdio.h>
//int main() {
//	char str[] = "this is A str to 4tipalize";
//	char str2[] = "                         ";
//	char str3[] = "                         ";
//	printf("%d\n", strlcpy(str2, str, 2));
//	printf("%s\n", str);
//	printf("%s\n", str2);
//	
//	printf("%d\n", ft_strlcpy(str3, str, 2));
//	printf("%s\n", str);
//	printf("%s\n", str3);
//	return 0;
//}
