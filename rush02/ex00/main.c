/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 11:13:54 by jule-mer          #+#    #+#             */
/*   Updated: 2021/08/22 23:29:34 by mprud-ho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_check_params(int argc, char **argv)
{
	int	i;

	i = -1;
	if (argc == 2)
	{
		while (argv[1][++i])
		{
			if (argv[1][i] < '0' || argv[1][i] > '9')
				return (-1);
		}
		return (2);
	}
	else if (argc == 3)
	{
		while (argv[2][++i])
		{
			if (argv[2][i] < '0' || argv[2][i] > '9')
				return (-1);
		}
		return (3);
	}
	else
		return (-1);
}

int	final_checks(char **lines, char *file)
{
	char	**check;
	char	*bckupfile;

	bckupfile = "./bckupfile";
	check = ft_open(bckupfile);
	if (check_dictionnary(lines) == -1)
	{
		write(2, "Dict Error\n", 11);
		return (0);
	}
	if (!ft_compare_dict(lines, check))
	{
		write(2, "Dict Error\n", 11);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char		**lines;
	t_dictio	dictio;
	char		*file;

	file = "./dictionary";
	if (ft_check_params(argc, argv) < 2)
	{
		write(2, "Error\n", 6);
		return (ft_check_params(argc, argv));
	}
	if (ft_check_params(argc, argv) == 2)
		lines = ft_open(file);
	if (ft_check_params(argc, argv) == 3)
		lines = ft_open(argv[1]);
	if (!final_checks(lines))
		return (-1);
	if (input_to_dictio(lines, &dictio) == -1)
		return (-1);
	ft_free(lines);
	if (ft_check_params(argc, argv) == 2)
		print(argv[1], dictio);
	if (ft_check_params(argc, argv) == 3)
		print(argv[2], dictio);
	return (0);
}
