/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprud-ho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 11:49:17 by mprud-ho          #+#    #+#             */
/*   Updated: 2021/08/22 22:36:10 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_put_in_tab(char *tab, char *tmp, int line)
{
	int	i;

	i = 0;
	while (i < line)
	{
		tab[i] = *tmp;
		i++;
		tmp++;
	}
	tab[i] = 0;
}

void	ft_ptit_malloc(char **tab, char *tmp, int lines)
{
	int	i;
	int	j;
	int	line;

	i = 0;
	j = 0;
	line = 0;
	while (tmp[i])
	{
		j = 0;
		while (tmp[j + i] != '\n')
			j++;
		tab[line] = malloc(sizeof(char) * (j + 1));
		if (!tab[line])
			return ;
		ft_put_in_tab(tab[line], tmp + i, j);
		j++;
		i = i + j;
		line++;
	}
}

char	**ft_tab(char *tmp)
{
	char	**tab;
	int		i;
	int		lines;
	int		check;

	i = 0;
	lines = 0;
	check = 0;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
			lines++;
		i++;
	}
	tab = malloc(sizeof(char *) * (lines + 1));
	if (!tab)
		return (NULL);
	tab[lines] = 0;
	ft_ptit_malloc(tab, tmp, lines);
	free(tmp);
	return (tab);
}

char	**ft_read(int fd, char **line)
{
	int		i;
	char	buf[9];
	char	*tmp;
	int		j;

	j = 0;
	tmp = malloc(sizeof(char) * 8);
	tmp[0] = '\0';
	if (fd < 0)
		return (NULL);
	while (1)
	{
		i = read(fd, buf, 8);
		if (i <= 0)
			break ;
		buf[i] = '\0';
		tmp = ft_strjoin(tmp, buf);
	}
	close(fd);
	line = ft_tab(tmp);
	return (line);
}

char	**ft_open(char *str)
{
	char	**line;
	int		fd;
	int		lines;

	fd = open(str, O_RDONLY);
	line = ft_read(fd, line);
	return (line);
}
