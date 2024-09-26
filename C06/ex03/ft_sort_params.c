/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 19:07:07 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/15 19:22:59 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	sort(char **to_sort, int size)
{
	int		i;
	int		j;
	int		min_idx;
	char	*tmp;

	i = -1;
	while (++i < size - 1)
	{
		min_idx = i;
		j = i;
		while (++j < size)
			if (ft_strcmp(to_sort[min_idx], to_sort[j]) > 0)
				min_idx = j;
		tmp = to_sort[min_idx];
		to_sort[min_idx] = to_sort[i];
		to_sort[i] = tmp;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		return (0);
	sort(&argv[1], argc - 1);
	i = 0;
	while (++i < argc)
	{
		ft_putstr(argv[i]);
		ft_putstr("\n");
	}
	return (0);
}
