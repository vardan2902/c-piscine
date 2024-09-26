/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 21:35:07 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/07 23:27:12 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	merge(int *left, int *right, int left_size, int right_size)
{
	int	i;
	int	j;
	int	k;
	int	temp;

	i = 0;
	j = 0;
	while (i < left_size && j < right_size)
	{
		if (left[i] > right[j])
		{
			ft_swap(&left[i], &right[j]);
			temp = right[j];
			k = j;
			while (k + 1 < right_size && right[k] > right[k + 1])
			{
				ft_swap(&right[k], &right[k + 1]);
				k++;
			}
		}
		else
			i++;
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	left_size;
	int	right_size;

	if (size <= 1)
		return ;
	left_size = size / 2;
	right_size = size - left_size;
	ft_sort_int_tab(tab, left_size);
	ft_sort_int_tab(&tab[left_size], right_size),
	merge(tab, &tab[left_size], left_size, right_size);
}
