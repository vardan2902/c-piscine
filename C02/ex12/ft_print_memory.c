/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:27:20 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/08 21:28:11 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

void	ft_putnbr_base(unsigned long nbr, char *base, int base_len)
{
	char	buffer[16];
	int		i;

	i = 0;
	while (nbr)
	{
		buffer[i++] = base[nbr % base_len];
		nbr /= base_len;
	}
	while (i < base_len--)
		write(1, "0", 1);
	while (i--)
		write(1, &buffer[i], 1);
}

void	ft_print_hex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, &hex[c / 16], 1);
	write(1, &hex[c % 16], 1);
}

void	ft_print_memory_line(unsigned long addr, unsigned char *data,
	unsigned int size)
{
	unsigned int	i;

	ft_putnbr_base(addr, "0123456789abcdef", 16);
	ft_putstr(": ");
	i = -1;
	while (++i < 16)
	{
		if (i < size)
			ft_print_hex(data[i]);
		else
			write(1, "  ", 2);
		if (i % 2 == 1)
			write(1, " ", 1);
	}
	i = -1;
	while (++i < size)
	{
		if (data[i] >= 32 && data[i] <= 126)
			write(1, &data[i], 1);
		else
			write(1, ".", 1);
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*data;
	unsigned int	i;
	unsigned int	line_size;

	data = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		if (size - i >= 16)
			line_size = 16;
		else
			line_size = size - i;
		ft_print_memory_line((unsigned long)&data[i], &data[i], line_size);
		i += 16;
	}
	return (addr);
}
