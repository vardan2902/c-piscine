/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 21:58:04 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/18 23:03:12 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	check_base(char *base);

int	get_num_len(int num, int radix)
{
	int	len;

	if (num <= 0)
		len = 1;
	else
		len = 0;
	while (num)
	{
		num /= radix;
		len++;
	}
	return (len);
}

int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

char	*ft_itoa_base(int num, char *base)
{
	int		radix;
	int		len;
	char	*result;

	radix = 0;
	while (base[radix])
		++radix;
	len = get_num_len(num, radix);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (num < 0)
		result[0] = '-';
	if (num == 0)
		result[0] = base[0];
	while (num)
	{
		result[--len] = base[ft_abs((num % radix))];
		num /= radix;
	}
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;

	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	num = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(num, base_to));
}
