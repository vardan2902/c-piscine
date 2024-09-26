/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 22:44:02 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/05 23:49:47 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(char combination[], int n)
{
	int	i;
	int	digit_index;

	i = -1;
	while (++i < n)
	{
		digit_index = combination[i];
		ft_putchar("0123456789"[digit_index]);
	}
}

void	ft_generate(char combination[], int n, int start, int depth)
{
	int	i;

	if (depth == n)
	{
		ft_print(combination, n);
		if (combination[0] != 10 - n)
			write(1, ", ", 2);
		return ;
	}
	i = start - 1;
	while (++i <= 10 - n + depth)
	{
		combination[depth] = i;
		ft_generate(combination, n, i + 1, depth + 1);
	}
}

void	ft_print_combn(int n)
{
	char	combinations[10];

	if (n < 1 || n > 9)
		return ;
	ft_generate(combinations, n, 0, 0);
}
