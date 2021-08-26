/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:51:24 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/25 22:42:12 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	err(void)
{
	ft_putstr(ERR, 2);
	return (-1);
}

int	read_and_print(int file_descriptor)
{
	char	buf[S_BUFF];
	int		i;
	int		len;

	len = S_BUFF;
	while (len == S_BUFF)
	{
		i = 0;
		len = read(file_descriptor, buf, S_BUFF);
		if (len == -1)
		{
			close(file_descriptor);
			return (err());
		}
		while (i < len)
			ft_putchar(buf[i++]);
	}
	close(file_descriptor);
	return (0);
}

int	main(int argc, char **argv)
{
	int	file_descriptor;

	if (argc == 2)
	{
		file_descriptor = open(argv[1], O_RDONLY);
		if (file_descriptor == -1)
			return (err());
		return (read_and_print(file_descriptor));
	}
	else if (argc == 1)
		ft_putstr(FILE_NAME_MISSING, 2);
	else if (argc >= 3)
		ft_putstr(TOO_MANY_ARGS, 2);
	return (-1);
}
