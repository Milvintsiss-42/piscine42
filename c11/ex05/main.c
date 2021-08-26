/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 18:27:47 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/24 23:17:06 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str);
void	ft_putnbr(int nbr);
int		ft_atoi(char *str);

int	main(int argc, char **argv)
{
	int	val1;
	int	val2;

	if (argc != 4)
		return (-1);
	val1 = ft_atoi(argv[1]);
	val2 = ft_atoi(argv[3]);
	if (argv[2][0] == '+' && argv[2][1] == '\0')
		ft_putnbr(val1 + val2);
	else if (argv[2][0] == '-' && argv[2][1] == '\0')
		ft_putnbr(val1 - val2);
	else if (argv[2][0] == '/' && argv[2][1] == '\0' && val2 == 0)
		ft_putstr("Stop : division by zero");
	else if (argv[2][0] == '/' && argv[2][1] == '\0')
		ft_putnbr(val1 / val2);
	else if (argv[2][0] == '*' && argv[2][1] == '\0')
		ft_putnbr(val1 * val2);
	else if (argv[2][0] == '%' && argv[2][1] == '\0' && val2 == 0)
		ft_putstr("Stop : modulo by zero");
	else if (argv[2][0] == '%' && argv[2][1] == '\0')
		ft_putnbr(val1 % val2);
	else
		ft_putstr("0");
	ft_putstr("\n");
	return (0);
}
