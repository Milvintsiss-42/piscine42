/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 20:20:20 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/25 17:57:10 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int					i;
	char				*temp;

	i = 0;
	if (tab[0] == 0)
		return ;
	while (tab[i + 1] != 0)
	{
		if ((*cmp)(tab[i], tab[i + 1]) > 0)
		{
			temp = tab[i];
			tab[i] = tab [i + 1];
			tab[i + 1] = temp;
			if (--i < 0)
				i = 0;
		}
		else
			i++;
	}	
}

/*
#include <unistd.h>

void	ft_putstr(char *str)
{
	unsigned long int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	argv[argc - 1] = 0;
	ft_advanced_sort_string_tab(argv, &ft_strcmp);
	while (argv[i])
		ft_putstr(argv[i++]);
	return (0);
}
*/
