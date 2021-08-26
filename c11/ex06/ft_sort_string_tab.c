/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:37:07 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/25 17:56:32 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_string_tab(char **tab)
{
	int					i;
	unsigned long int	j;
	char				*temp;

	i = 0;
	if (tab[0] == 0)
		return ;
	while (tab[i + 1] != 0)
	{
		j = 0;
		while (tab[i][j] == tab[i + 1][j] && tab[i][j] && tab[i + 1][j])
			j++;
		if (tab[i][j] > tab[i + 1][j])
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

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	argv[argc - 1] = 0;
	ft_sort_string_tab(argv);
	while (argv[i])
		ft_putstr(argv[i++]);
	return (0);
}
*/
