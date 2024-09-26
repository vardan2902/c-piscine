/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 01:31:38 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/25 01:08:59 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/errno.h>
#include <fcntl.h>
#include <sys/types.h>

void	ft_putstr_fd(char *str, int fd);
int		ft_atoi(char *str);
void	ft_puterr_str(char *str);
int		open_file(char *filename);
void	close_file(int fd);
void	print_last_bytes(char *buffer, ssize_t total_size, int byte_count);
ssize_t	read_input(int fd, char **buffer);
int		ft_strcmp(char *s1, char *s2);
int		ft_putname(char *str);

void	ft_tail(int argc, char *filename, int byte_count, int *err)
{
	int		fd;
	ssize_t	total_size;
	char	*buffer;

	buffer = NULL;
	fd = open_file(filename);
	if (fd == -1)
	{
		*err = 1;
		return ;
	}
	if (argc > 4)
		ft_putname(filename);
	total_size = read_input(fd, &buffer);
	if (total_size == -1)
		return (close_file(fd));
	print_last_bytes(buffer, total_size, byte_count);
	free(buffer);
	close_file(fd);
}

int	is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v' || c == '\f');
}

int	check_bytes(char *str)
{
	int	i;

	i = 0;
	while (is_space(str[i]))
		++i;
	if (str[i] == '-' || str[i] == '+')
		++i;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			break ;
		++i;
	}
	return (str[i] == '\0');
}

int	check_errors(int argc, char **argv)
{
	if (argc < 3 || ft_strcmp(argv[1], "-c"))
	{
		ft_puterr_str("option requires an argument -- c\n\
usage: ft_tail -c # [file ...]");
		return (0);
	}
	if (!check_bytes(argv[2]))
	{
		ft_putstr_fd("ft_tail: illegal offset -- ", 2);
		ft_putstr_fd(argv[2], 2);
		ft_putstr_fd("\n", 2);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	n;
	int	i;
	int	err;

	err = 0;
	if (!check_errors(argc, argv))
		return (1);
	n = ft_atoi(argv[2]);
	if (argc < 4)
		ft_tail(argc, NULL, n, &err);
	i = 2;
	while (++i < argc)
		ft_tail(argc, argv[i], n, &err);
	return (err);
}
