/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 21:57:10 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/17 19:29:39 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int					i;
	unsigned long int	j;
	char				*temp;

	i = 1;
	while (i < argc - 1)
	{
		j = 0;
		while (argv[i][j] == argv[i + 1][j] && argv[i][j] && argv[i + 1][j])
			j++;
		if (argv[i][j] > argv[i + 1][j])
		{
			temp = argv[i];
			argv[i] = argv [i + 1];
			argv[i + 1] = temp;
			if (--i < 1)
				i = 1;
		}
		else
			i++;
	}
	i = 1;
	while (i < argc)
		ft_putstr(argv[i++]);
}
