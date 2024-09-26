/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:11:00 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/21 15:41:10 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

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

t_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*tab;

	tab = (t_stock_str *)malloc((ac + 1) * sizeof (t_stock_str));
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		if (!tab[i].copy)
		{
			while (--i >= 0)
				free(tab[i].copy);
			free(tab);
			return (NULL);
		}
	}
	tab[i].str = 0;
	return (tab);
}
