/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 01:54:52 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/22 18:25:54 by ligityan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	count_digits(int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

static void	fill_str_with_digits(char *str, int num, int len)
{
	str[len] = '\0';
	if (num == 0)
		str[0] = '0';
	else
	{
		while (num != 0)
		{
			str[--len] = (num % 10) + '0';
			num /= 10;
		}
	}
}

char	*ft_itoa(int num)
{
	int		len;
	char	*str;

	len = count_digits(num);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	fill_str_with_digits(str, num, len);
	return (str);
}
