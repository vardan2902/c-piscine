/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:47:05 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/07 15:51:39 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

void	print_for_pos(int x, int y, int curr_y, int curr_x)
{
	if (curr_y == 0)
	{
		if (curr_x == 0 || curr_x == x - 1)
			return (ft_putchar('A'));
		return (ft_putchar('B'));
	}
	if (curr_y == y - 1)
	{
		if (curr_x == 0 || curr_x == x - 1)
			return (ft_putchar('C'));
		return (ft_putchar('B'));
	}
	if (curr_x == 0 || curr_x == x - 1)
		return (ft_putchar('B'));
	return (ft_putchar(' '));
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	if (x > 150 || y > 150)
		return (ft_putstr("Arguments out of bounds,\
please provide integers between 1 and 150"));
	i = -1;
	while (++i < y)
	{
		j = -1;
		while (++j < x)
			print_for_pos(x, y, i, j);
		ft_putchar('\n');
	}
}
