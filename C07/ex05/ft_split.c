/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 21:01:00 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/21 01:17:16 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	contains(char *charset, char c)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (c == charset[i])
			return (1);
	return (0);
}

int	get_word_len(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !contains(charset, str[i]))
		++i;
	return (i);
}

int	count_words(char *str, char *charset)
{
	int	wc;
	int	i;

	i = -1;
	wc = 0;
	while (str[++i])
	{
		if ((i == 0 && !contains(charset, str[i]))
			|| (i != 0 && contains(charset, str[i - 1])
				&& !contains(charset, str[i])))
			++wc;
	}
	return (wc);
}

char	**ft_fn(int idx[3], char **splitted, char *str, char *charset)
{
	int	word_len;

	while (str[idx[1]] && contains(charset, str[idx[1]]))
		++idx[1];
	word_len = get_word_len(&str[idx[1]], charset);
	splitted[idx[0]] = (char *)malloc((word_len + 1) * sizeof (char));
	if (!splitted[idx[0]])
		return (NULL);
	idx[2] = 0;
	while (str[idx[1]] && !contains(charset, str[idx[1]]))
		splitted[idx[0]][idx[2]++] = str[idx[1]++];
	splitted[idx[0]][idx[2]] = '\0';
	return (splitted);
}

char	**ft_split(char *str, char *charset)
{
	char	**splitted;
	int		wc;
	int		idx[3];

	if (!str || !charset)
		return (NULL);
	wc = count_words(str, charset);
	splitted = (char **)malloc((wc + 1) * sizeof (char *));
	if (!splitted)
		return (NULL);
	if (wc == 0)
	{
		splitted[0] = NULL;
		return (splitted);
	}
	idx[0] = -1;
	idx[1] = 0;
	while (++idx[0] < wc)
		if (!ft_fn(idx, splitted, str, charset))
			return (NULL);
	splitted[idx[0]] = NULL;
	return (splitted);
}
