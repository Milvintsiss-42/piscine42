/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:51:24 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/26 19:10:24 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	err(t_err err_data)
{
	ft_putstr(err_data.bin_name, 1);
	ft_putstr(": ", 2);
	ft_putstr(err_data.file_name, 1);
	ft_putstr(": ", 2);
	ft_putstr(strerror(errno), 1);
	ft_putchar('\n', 1);
	return (-1);
}

int	read_and_print(int file_descriptor)
{
	char	buf[8];
	int		i;
	int		len;

	len = 8;
	while (len == 8)
	{
		i = 0;
		len = read(file_descriptor, buf, 8);
		if (len == -1)
		{
			close(file_descriptor);
			return (-1);
		}
		while (i < len)
			ft_putchar(buf[i++], 1);
	}
	if (file_descriptor == STDIN_FILENO && (buf[len - 1] == '\n' || len > 0))
		read_and_print(STDIN_FILENO);
	if (file_descriptor != STDIN_FILENO)
		close(file_descriptor);
	return (0);
}

void	read_from_args(char **files_o_stdin, int len, t_err err_data)
{
	int	i;
	int	file_descriptor;

	i = 0;
	while (i < len)
	{
		/*if (files_o_stdin[i][0] == '-')
		{
			err_data.file_name = err_data.bin_name;
			file_descriptor = STDIN_FILENO;
		}
		else
		{*/
			err_data.file_name = files_o_stdin[i];
			file_descriptor = open(files_o_stdin[i], O_RDONLY);
		//}
		if (file_descriptor == -1 || read_and_print(file_descriptor) == -1)
			err(err_data);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_err	err_data;

	err_data.bin_name = basename(argv[0]);
	if (argc >= 2)
	{
		read_from_args(argv + 1, argc - 1, err_data);
		return (0);
	}
	else
	{
		err_data.file_name = err_data.bin_name;
		if (read_and_print(STDIN_FILENO))
			return (err(err_data));
	}
	return (-1);
}
