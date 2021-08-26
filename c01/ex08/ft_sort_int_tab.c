/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 13:06:53 by ple-stra          #+#    #+#             */
/*   Updated: 2021/08/07 02:54:43 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = i - 2;
			if (i < 0)
				i = -1;
		}
		i++;
	}
}

//int	main(void)
//{
//	int tab[] = {4, 6, 2, 6, 9};
//	ft_sort_int_tab(tab, 5);
//	return (0);
//}
