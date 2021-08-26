/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 11:06:00 by jule-mer          #+#    #+#             */
/*   Updated: 2021/08/22 23:43:31 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/*
** structures
*/
typedef struct s_power_dictio
{
	char			n;
	unsigned int	len;
	char			*str;
}	t_power_dictio;

typedef struct s_except_dictio
{
	char	*nbr;
	char	*str;
}	t_except_dictio;

typedef struct s_dictio
{
	char 			**digit;
	t_power_dictio	*power;
	t_except_dictio	*except;
}	t_dictio;

/*
** main.c
*/
int			ft_check_params(int argc, char **argv);
int			main(int argc, char **argv);

/*
** read.c
*/
void		ft_put_int_tab(char *tab, char *str, int line);
void		ft_ptit_malloc(char **tab, char *tmp, int lines);
char		**ft_tab(char *tmp);
char		**ft_read(int fd, char **line);
char		**ft_open(char *str);

/*
** ft_strs
*/
int			ft_srch(char *str, char c);
char		*ft_strjoin(char *s1, char *s2);
int			ft_which_number(char *str);
int			ft_strcmp(char *s1, char *s2);
int			ft_strncmp_custom(char *s1, char *s2, unsigned int n);
int			ft_strncmp(char *s1, char *s2, int n);

/*
** ft_check_dict
*/
int			check_dictionnary(char **lines);
int			check_doubles(char **lines);
int			nb_len(char *str);
int			ft_valid(char *str);

/*
** ft_check_dict2
*/

int			check_doubles2(char **lines);
int			same(char *s1, char *s2);
int			wrd_len(char *str);

/*
** ft_in_struct
*/
int			input_to_dictio(char **lines, t_dictio *dictio);
t_dictio	sort(int type, char *str);
void		ft_which_one(char **tab);
int			assign_power(char **lines, t_dictio *dictio);
int			assign_except(char **lines, t_dictio *dictio);


/*
** count_occ_types
*/
int	is_exception(char *str);
int	is_power(char *str);
unsigned int	count_exceptions(char **tab);
unsigned int	count_powers(char **tab);
unsigned int	count_digits(char **tab);
int				assign_digits(char **lines, t_dictio *dictio);

/*
** print
*/

void	get_power(char n, int len, t_dictio dictio, int has_space);
void	print(char *nbr, t_dictio dictio);
unsigned int 	ft_strlen(char *str);

/*
** ft_free
*/
void	ft_free(char **lines);

void	ft_putstr(char *str, int b_has_space);
unsigned int	ft_strlen(char *str);

#endif
