/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:08:32 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/10 20:37:37 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (!to_find || !to_find[0])
		return (str);
	i = -1;
	while (str[++i])
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (str[i + j] == to_find[j])
				++j;
			if (!to_find[j])
				return (&str[i]);
		}
	}
	return ((void *)0);
}
