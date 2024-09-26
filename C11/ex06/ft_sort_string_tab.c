/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 21:19:26 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/25 22:23:36 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_sort_string_tab(char **tab)
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
			if (ft_strcmp(tab[min_idx], tab[j]) > 0)
				min_idx = j;
		tmp = tab[i];
		tab[i] = tab[min_idx];
		tab[min_idx] = tmp;
	}
}
