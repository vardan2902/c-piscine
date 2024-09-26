/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 19:42:55 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/15 19:57:33 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;

	if (min >= max)
		return ((void *)0);
	range = (int *)malloc((max - min) * sizeof (int));
	if (!range)
		return ((void *)0);
	i = -1;
	while (min + (++i) < max)
		range[i] = min + i;
	return (range);
}
