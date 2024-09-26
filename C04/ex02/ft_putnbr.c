/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 22:09:25 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/15 20:34:10 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
