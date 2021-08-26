/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 21:47:22 by mastie            #+#    #+#             */
/*   Updated: 2021/08/16 01:19:14 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLIB_H
# define MYLIB_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_putstr_err(char *str);
void	*free_tab(int **limit, char *str);
int		**create_the_playground(int **limit, int size);
void	ft_print(int **limit, int size);
int		solver(int **pg, int **limit, int coor, int size);
int		is_already_in_col_o_row(int value, int **pg, int coor, int size);
int		check_col(int **pg, int **limit, int x, int size);
int		check_row(int **pg, int **limit, int y, int size);
void	print_playground(int **playground, int size);

#endif
