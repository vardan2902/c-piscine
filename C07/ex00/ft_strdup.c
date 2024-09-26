/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 19:32:54 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/15 19:37:50 by vapetros         ###   ########.fr       */
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

char	*ft_strdup(char *src)
{
	unsigned int	len;
	unsigned int	i;
	char			*dest;

	len = ft_strlen(src);
	dest = (char *)malloc((len + 1) * sizeof (char));
	if (!dest)
		return ((void *)0);
	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
