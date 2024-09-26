/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:19:55 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/13 21:38:36 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	return ('\t' == c || '\n' == c || '\v' == c
		|| '\f' == c || '\r' == c || ' ' == c);
}

void	skip_spaces(char *str, int *pos)
{
	while (str[*pos] && ft_isspace(str[*pos]))
		++*pos;
}

int	get_num(char *str, int *pos)
{
	long int	num;

	num = 0;
	while (str[*pos] && str[*pos] >= '0' && str[*pos] <= '9')
	{
		num = num * 10 + (str[*pos] - '0');
		++*pos;
	}
	return (num);
}

int	get_sign(char *str, int *pos)
{
	int	sign;

	sign = 1;
	while (str[*pos] && (str[*pos] == '+' || str[*pos] == '-'))
	{
		if (str[*pos] == '-')
			sign = -sign;
		++*pos;
	}
	return (sign);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	skip_spaces(str, &i);
	sign = get_sign(str, &i);
	num = get_num(str, &i);
	return (sign * num);
}
