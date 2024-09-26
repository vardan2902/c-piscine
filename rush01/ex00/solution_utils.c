/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:20:47 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/15 14:03:04 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	**ft_init_board(int size)
{
	int	i;
	int	j;
	int	**board;

	board = (int **)malloc(size * sizeof (int *));
	i = -1;
	while (++i < size)
		board[i] = (int *)malloc(size * sizeof (int));
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			board[i][j] = 0;
	}
	return (board);
}

int	ft_check_up_down(int y, int **board, int size, int **rules)
{
	int	i;
	int	max[2];
	int	counter[2];

	i = -1;
	max[0] = 0;
	max[1] = 0;
	counter[0] = 0;
	counter[1] = 0;
	while (++i < size)
	{
		if (max[1] < board[size - 1 - i][y])
		{
			max[1] = board[size - 1 - i][y];
			++counter[1];
		}
		if (max[0] < board[i][y])
		{
			max[0] = board[i][y];
			++counter[0];
		}
	}
	return (!(counter[0] != rules[0][y] || counter[1] != rules[1][y]));
}

int	ft_check_left_right(int x, int **board, int size, int **rules)
{
	int	i;
	int	max[2];
	int	counter[2];

	i = -1;
	max[0] = 0;
	max[1] = 0;
	counter[0] = 0;
	counter[1] = 0;
	while (++i < size)
	{
		if (max[1] < board[x][size - 1 - i])
		{
			max[1] = board[x][size - 1 - i];
			++counter[1];
		}
		if (max[0] < board[x][i])
		{
			max[0] = board[x][i];
			++counter[0];
		}
	}
	return (!(counter[0] != rules[2][x] || counter[1] != rules[3][x]));
}

int	ft_check_up_left_before_finish(int indexes[2],
	int **board, int size, int **rules)
{
	int	i;
	int	max[2];
	int	counter[2];

	i = -1;
	max[0] = 0;
	max[1] = 0;
	counter[0] = 0;
	counter[1] = 0;
	while (++i < size)
	{
		if (max[1] < board[i][indexes[1]])
		{
			max[1] = board[i][indexes[1]];
			++counter[1];
		}
		if (max[0] < board[indexes[0]][i])
		{
			max[0] = board[indexes[0]][i];
			++counter[0];
		}
	}
	return (counter[1] <= rules[0][indexes[1]]
		&& counter[0] <= rules[2][indexes[0]]);
}

int	ft_check(int indexes[2], int **board, int size, int **rules)
{
	int	i;

	i = -1;
	while (++i < size)
		if ((board[i][indexes[1]] == board[indexes[0]][indexes[1]]
			&& i != indexes[0] && board[i][indexes[1]] != 0)
			|| (board[indexes[0]][i] == board[indexes[0]][indexes[1]]
			&& i != indexes[1] && board[indexes[0]][i] != 0))
			return (0);
	if ((indexes[0] != size - 1 || indexes[1] != size -1)
		&& !ft_check_up_left_before_finish(indexes, board, size, rules))
		return (0);
	if (indexes[0] == size - 1)
		if (!ft_check_up_down(indexes[1], board, size, rules))
			return (0);
	if (indexes[1] == size - 1)
		if (!ft_check_left_right(indexes[0], board, size, rules))
			return (0);
	return (1);
}
