/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:23:51 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/08 21:48:11 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_printable(char c)
{
	return (c > 31 && c < 127);
}

int	ft_str_is_printable(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!is_printable(str[i]))
			return (0);
	return (1);
}
