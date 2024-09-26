/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:35:01 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/22 22:52:45 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/errno.h>
#include <libgen.h>

#define BUFFER_SIZE 30000

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

void	ft_puterr(char *path)
{
	ft_putstr_fd("ft_cat: ", 2);
	ft_putstr_fd(basename(path), 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
}

void	ft_cat(char *filename)
{
	int		fd;
	ssize_t	bytes_read;
	char	buffer[BUFFER_SIZE];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_puterr(filename));
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		write(1, buffer, bytes_read);
	}
	if (bytes_read == -1)
		return (ft_puterr(filename));
	if (close(fd) == -1)
		return (ft_puterr(filename));
}

void	ft_read_stdin(void)
{
	int		bytes_read;
	char	buffer[BUFFER_SIZE];

	while (1)
	{
		bytes_read = read(0, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		write(1, buffer, bytes_read);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 2)
		ft_read_stdin();
	while (++i < argc)
		ft_cat(argv[i]);
	return (0);
}
