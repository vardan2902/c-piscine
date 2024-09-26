/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:12:30 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/19 22:54:11 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = -1;
	while (str[++len])
		;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (dest[++i])
		;
	while (src[++j])
		dest[i++] = src[j];
	dest[i] = '\0';
	return (dest);
}

void	concat(int size, char **strs, char *sep, char *res)
{
	int	i;

	res[0] = '\0';
	i = -1;
	while (++i < size)
	{
		ft_strcat(res, strs[i]);
		if (i != size - 1)
			ft_strcat(res, sep);
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char			*result;
	unsigned int	sep_len;
	unsigned int	strs_len;
	int				i;

	if (!size)
	{
		result = (char *)malloc(sizeof (char));
		result[0] = '\0';
		return (result);
	}
	sep_len = ft_strlen(sep);
	strs_len = 0;
	i = -1;
	while (++i < size)
		strs_len += ft_strlen(strs[i]);
	result = (char *)malloc((strs_len + 1 + \
		(size - 1) * sep_len) * sizeof (char));
	concat(size, strs, sep, result);
	return (result);
}
