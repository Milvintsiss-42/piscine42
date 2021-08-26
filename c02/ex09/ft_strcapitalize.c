/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:34:35 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/10 14:30:12 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + ('a' - 'A');
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	unsigned int	i;
	int				is_alpha;
	int				precedent_not_alpha;

	i = 1;
	str = ft_strlowcase(str);
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - ('a' - 'A');
	while (str[i] != '\0')
	{
		is_alpha = str[i] >= 'a' && str[i] <= 'z';
		precedent_not_alpha = str[i - 1] < '0'
			|| (str[i - 1] > '9' && str[i - 1] < 'A')
			|| (str[i - 1] > 'Z' && str[i - 1] < 'a')
			|| str[i - 1] > 'z';
		if (is_alpha && precedent_not_alpha)
			str[i] = str[i] - ('a' - 'A');
		i++;
	}
	return (str);
}
