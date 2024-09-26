/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:44:27 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/12 20:53:54 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = -1;
	while (base[++i])
		if (base[i] == '-' || base[i] == '+')
			return (0);
	i = -1;
	while (base[++i])
	{
		j = i;
		while (base[++j])
			if (base[i] == base[j])
				return (0);
	}
	return (1);
}

long int	ft_abs(long int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			radix;
	char		current;

	radix = ft_strlen(base);
	if (radix <= 1 || !check_base(base))
		return ;
	if (nbr < 0)
		ft_putchar('-');
	current = base[ft_abs(nbr % radix)];
	if (ft_abs(nbr) >= radix)
		ft_putnbr_base(ft_abs(nbr / radix), base);
	ft_putchar(current);
}
