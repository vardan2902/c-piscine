/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 19:52:22 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/19 21:02:22 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int				i;

	if (min >= max)
	{
		*range = (void *)0;
		return (0);
	}
	*range = (int *)malloc((max - min) * sizeof (int));
	if (!*range)
		return (-1);
	i = -1;
	while (min + (++i) < max)
		(*range)[i] = min + i;
	return (max - min);
}
