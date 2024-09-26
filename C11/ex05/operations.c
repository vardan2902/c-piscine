/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 21:00:09 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/23 21:02:27 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	add(int a, int b)
{
	return (a + b);
}

int	sub(int a, int b)
{
	return (a - b);
}

int	mul(int a, int b)
{
	return (a * b);
}

int	div(int a, int b)
{
	if (b == 0)
		return (0);
	return (a / b);
}

int	mod(int a, int b)
{
	if (b == 0)
		return (0);
	return (a % b);
}
