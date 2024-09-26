/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 21:20:08 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/25 22:24:20 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab,
	int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	int		min_idx;
	char	*tmp;

	if (!tab)
		return ;
	i = -1;
	while (tab[++i + 1])
	{
		j = i;
		min_idx = i;
		while (tab[++j])
			if (cmp(tab[min_idx], tab[j]) > 0)
				min_idx = j;
		tmp = tab[i];
		tab[i] = tab[min_idx];
		tab[min_idx] = tmp;
	}
}
