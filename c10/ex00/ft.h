/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:53:10 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/26 22:13:20 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# define FILE_NAME_MISSING "File name missing.\n"
# define TOO_MANY_ARGS "Too many arguments.\n"
# define ERR "Cannot read file.\n"

# define S_BUFF 250

# include <fcntl.h>
# include <unistd.h>

void	ft_putstr(char *str, int channel);

#endif
