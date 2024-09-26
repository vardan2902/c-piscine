/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:41:48 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/05 22:06:20 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_num(char n)
{
	char	num1;
	char	num2;

	num2 = n % 10 + 48;
	num1 = n / 10 + 48;
	write(1, &num1, 1);
	write(1, &num2, 1);
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;

	a = -1;
	while (++a < 100)
	{
		b = a;
		while (++b < 100)
		{
			ft_print_num(a);
			write(1, " ", 1);
			ft_print_num(b);
			if (a != 98)
				write(1, ", ", 2);
		}
	}
}
