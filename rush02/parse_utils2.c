/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:06:29 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/22 21:34:51 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	get_next_line(char **line, char *content, int *start)
{
	int	end;

	while (content[*start] == '\n')
		*start += 1;
	end = *start;
	while (content[end] && content[end] != '\n')
		++end;
	if (end > *start)
	{
		*line = (char *)malloc((end - *start + 1) * sizeof (char));
		if (!*line)
			return (-1);
		ft_strncpy(*line, content + *start, end - *start);
		(*line)[end - *start] = '\0';
		if (content[end])
			*start = end + 1;
		else
			*start = end;
		return (1);
	}
	return (0);
}

static char	*trim_spaces(char *str)
{
	char			*end;
	unsigned int	len;
	char			*trimmed;

	while (is_space(*str))
		str++;
	if (*str == '+')
		str++;
	if (*str == '\0')
		return (ft_strdup(""));
	end = str + ft_strlen(str) - 1;
	while (end > str && is_space(*end))
		end--;
	len = end - str + 1;
	trimmed = (char *)malloc((len + 1) * sizeof (char));
	if (!trimmed)
		return (NULL);
	ft_strncpy(trimmed, str, len);
	trimmed[len] = '\0';
	return (trimmed);
}

t_dict_entry	*parse_dictionary(char *dict_content)
{
	t_dict_entry	*dictionary;
	int				i;
	int				start;
	char			*line;
	char			*colon;

	i = 0;
	start = 0;
	line = NULL;
	dictionary = malloc(sizeof(t_dict_entry) * 100);
	while (get_next_line(&line, dict_content, &start) > 0)
	{
		colon = ft_strchr(line, ':');
		if (colon)
		{
			*colon = '\0';
			dictionary[i].number = ft_strdup(trim_spaces(line));
			dictionary[i].text = ft_strdup(trim_spaces(colon + 1));
			i++;
		}
		free(line);
	}
	return (dictionary);
}

int	get_num_pos(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
		if (arg[i] >= '0' && arg[i] <= '9')
			return (i);
	return (0);
}
