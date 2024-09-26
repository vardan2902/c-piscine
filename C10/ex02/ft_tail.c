/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:41:59 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/25 00:46:11 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/errno.h>

#define BUFFER_SIZE 1024

void	ft_putstr_fd(char *str, int fd);
void	ft_putname(char *path);
void	ft_puterr(char *path);
void	ft_puterr_str(char *str);
int		ft_strcmp(char *s1, char *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_realloc(void *ptr, size_t original_size, size_t new_size);

int	open_file(char *filename)
{
	int	fd;

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_puterr(filename);
	return (fd);
}

int	read_content(int fd, ssize_t *total_size, char **temp_buffer)
{
	ssize_t	bytes_read;
	char	*new_buffer;
	char	temp[BUFFER_SIZE];

	while (1)
	{
		bytes_read = read(fd, temp, sizeof(temp));
		if (bytes_read <= 0)
			break ;
		new_buffer = (char *)ft_realloc(*temp_buffer, *total_size, \
*total_size + bytes_read);
		if (!new_buffer)
		{
			free(*temp_buffer);
			ft_puterr_str(strerror(errno));
			ft_puterr_str("\n");
			return (-1);
		}
		*temp_buffer = new_buffer;
		ft_memcpy(*temp_buffer + *total_size, temp, bytes_read);
		*total_size += bytes_read;
	}
	return (bytes_read);
}

ssize_t	read_input(int fd, char **buffer)
{
	ssize_t	total_size;
	ssize_t	bytes_read;
	char	*temp_buffer;

	total_size = 0;
	temp_buffer = NULL;
	bytes_read = read_content(fd, &total_size, &temp_buffer);
	if (bytes_read == -1)
	{
		free(temp_buffer);
		return (-1);
	}
	*buffer = temp_buffer;
	return (total_size);
}

void	print_last_bytes(char *buffer, ssize_t total_size, int byte_count)
{
	if (byte_count > total_size)
		byte_count = total_size;
	write(1, buffer + (total_size - byte_count), byte_count);
}

void	close_file(int fd)
{
	if (fd > 0 && close(fd) == -1)
	{
		ft_puterr_str(strerror(errno));
		ft_puterr_str("\n");
	}
}
