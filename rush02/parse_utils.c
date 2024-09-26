/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:44:33 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/22 20:58:09 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\v'
		|| c == '\f' || c == '\r' || c == '\n');
}

int	is_valid_number(char *str)
{
	int	i;
	int	num_pos;

	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	num_pos = i;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.' || (str[i] < '0' && str[i] != '\0' && str[i] != ' '))
		return (0);
	while (is_space(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (i);
}

char	*append_to_content(char *content, char *buffer,
	int bytes_read, int *total_size)
{
	int		new_size;
	char	*new_content;

	new_size = *total_size + bytes_read + 1;
	new_content = (char *)malloc(new_size * sizeof (char));
	if (!new_content)
	{
		free(content);
		return (NULL);
	}
	ft_strcpy(new_content, content);
	ft_strncat(new_content, buffer, bytes_read);
	free(content);
	*total_size += bytes_read;
	return (new_content);
}

char	*read_file(int fd)
{
	char	buffer[4096];
	char	*content;
	int		bytes_read;
	int		total_size;

	total_size = 0;
	content = (char *)malloc(sizeof (char));
	if (!content)
		return (NULL);
	content[0] = '\0';
	while (1)
	{
		bytes_read = read(fd, buffer, 4096);
		if (bytes_read <= 0)
			break ;
		content = append_to_content(content, buffer, bytes_read, &total_size);
		if (!content)
			return (NULL);
	}
	return (content);
}

char	*read_file_content(char *filename)
{
	int		fd;
	char	*content;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	content = read_file(fd);
	close(fd);
	return (content);
}
