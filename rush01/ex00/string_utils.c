/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:50:11 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/15 13:24:26 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

void	ft_puterror(void)
{
	ft_putstr("Error\n");
}

int	is_str_valid(char *str)
{
	int	i;

	i = -1;
	while (str[i])
		if (!((i % 2 == 0 && (str[i] >= '1' && str[i] <= '9'))
				|| (i % 2 && str[i] == ' ')))
			return (0);
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[++i])
		;
	return (i);
}
