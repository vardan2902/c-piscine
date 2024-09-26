/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:13:08 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/09 21:06:28 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_non_printable(char c)
{
	return (c == 127 || c < 32);
}

void	print_non_printable(char c)
{
	char			*hex;
	unsigned int	pos;

	pos = (unsigned int)c;
	hex = "0123456789abcdef";
	ft_putchar('\\');
	ft_putchar(hex[pos / 16]);
	ft_putchar(hex[pos % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	i;

	i = -1;
	while (str[++i])
	{
		if (is_non_printable(str[i]))
			print_non_printable(str[i]);
		else
			ft_putchar(str[i]);
	}
}
