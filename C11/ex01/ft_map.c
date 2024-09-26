/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:28:43 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/23 21:23:09 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*new_tab;
	int	i;

	new_tab = (int *)malloc(length * sizeof (int));
	if (!new_tab)
		return (NULL);
	i = -1;
	while (++i < length)
		new_tab[i] = f(tab[i]);
	return (new_tab);
}
