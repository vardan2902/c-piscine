/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:05:12 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/15 17:08:50 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	left;
	int	right;
	int	mid;
	int	sqrt;

	if (nb < 0)
		return (0);
	left = 0;
	right = nb;
	while (left <= right)
	{
		mid = (left + right) / 2;
		sqrt = mid * mid;
		if (sqrt == nb)
			return (mid);
		else if (sqrt < nb)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (0);
}
