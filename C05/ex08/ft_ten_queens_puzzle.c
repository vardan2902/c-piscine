/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:58:21 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/16 21:10:32 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define N 10

int		ft_ten_queens_puzzle(void);
int		ft_check(int board[N][N], int x, int y);
int		ft_solution(int board[N][N], int x, int *total_count);
void	ft_putnbr(int nbr);
void	ft_print_solution(int board[N][N]);

int	ft_ten_queens_puzzle(void)
{
	int	total_count;
	int	i;
	int	j;
	int	board[N][N];

	total_count = 0;
	i = -1;
	while (++i < N)
	{
		j = -1;
		while (++j < N)
			board[i][j] = 0;
	}
	ft_solution(board, 0, &total_count);
	return (total_count);
}

int	ft_solution(int board[N][N], int x, int *total_count)
{
	int	y;

	y = -1;
	while (++y < N)
	{
		board[x][y] = 1;
		if (ft_check(board, x, y))
		{
			if (x < N - 1)
				ft_solution(board, x + 1, total_count);
			if (x == N - 1)
			{
				ft_print_solution(board);
				*total_count += 1;
			}
		}
		board[x][y] = 0;
	}
	return (0);
}

int	ft_check(int board[N][N], int x, int y)
{
	int	i;

	i = -1;
	while (++i < N)
	{
		if (board[i][y] && x != i)
			return (0);
		if (board[x][i] && y != i)
			return (0);
		if (x - i >= 0 && y - i >= 0 && i)
			if (board[x - i][y - i])
				return (0);
		if (x - i >= 0 && y + i < N && i)
			if (board[x - i][y + i])
				return (0);
	}
	return (1);
}

void	ft_print_solution(int board[N][N])
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (++i < N)
	{
		j = -1;
		while (++j < N)
		{
			if (board[i][j] == 1)
			{
				c = j + 48;
				write(1, &c, 1);
			}
		}
	}
	write(1, "\n", 1);
}

void	ft_putnbr(int nbr)
{
	char	c;

	c = nbr % 10 + 48;
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	write(1, &c, 1);
}
