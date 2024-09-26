/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:07:53 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/18 22:13:18 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	return ('\t' == c || '\n' == c || '\v' == c
		|| '\f' == c || '\r' == c || ' ' == c);
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

	if (ft_strlen(base) <= 1)
		return (0);
	i = -1;
	while (base[++i])
	{
		if (base[i] == '-' || base[i] == '+' || ft_isspace(base[i]))
			return (0);
		j = i;
		while (base[++j])
			if (base[i] == base[j])
				return (0);
	}
	return (1);
}

int	get_num(char *str, char *base, int radix)
{
	int	i;
	int	j;
	int	num;

	num = 0;
	i = -1;
	while (str[++i])
	{
		j = -1;
		while (base[++j])
			if (base[j] == str[i])
				break ;
		if (!base[j])
			return (num);
		num = num * radix + j;
	}
	return (num);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	num;
	int	radix;

	radix = ft_strlen(base);
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	num = get_num(&str[i], base, radix);
	return (sign * num);
}
