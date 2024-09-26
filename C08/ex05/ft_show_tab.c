/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:30:23 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/21 15:44:26 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_abs(int c)
{
	if (c < 0)
		return (-c);
	return (c);
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb < 0)
		ft_putchar('-');
	c = ft_abs(nb % 10) + 48;
	nb = ft_abs(nb / 10);
	if (nb != 0)
		ft_putnbr(nb);
	ft_putchar(c);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	if (!par)
		return ;
	i = -1;
	while (par[++i].str)
	{
		ft_putstr(par[i].str);
		ft_putstr("\n");
		ft_putnbr(par[i].size);
		ft_putstr("\n");
		ft_putstr(par[i].copy);
		ft_putstr("\n");
	}
}
