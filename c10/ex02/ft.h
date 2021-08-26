/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:53:10 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/26 16:42:03 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <sys/errno.h>
# include <libgen.h>

typedef struct s_err
{
	char	*bin_name;
	char	*file_name;
}	t_err;

// main.c
int		err(t_err err_data);

// ft_putstr.c
void	ft_putstr(char *str, int channel);
void	ft_putchar(char c, int channel);
#endif
