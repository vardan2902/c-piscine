/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:17:09 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/14 21:16:26 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sky_scraper(int **board, int size, int indexes[2], int **rules);
int		ft_check(int indexes[2], int **board, int size, int **rules);
void	ft_putchar(char c);

int	check_next_col(int **board, int size, int indexes[2], int **rules)
{
	int	next[2];

	next[0] = indexes[0];
	next[1] = indexes[1] + 1;
	return (ft_sky_scraper(board, size, next, rules));
}

int	check_next_row(int **board, int size, int indexes[2], int **rules)
{
	int	next[2];

	next[0] = indexes[0] + 1;
	next[1] = 0;
	return (ft_sky_scraper(board, size, next, rules));
}

int	ft_sky_scraper(int **board, int size, int indexes[2], int **rules)
{
	int	value;
	int	solution_found;

	value = 0;
	while (++value <= size)
	{
		board[indexes[0]][indexes[1]] = value;
		if (!ft_check(indexes, board, size, rules))
			continue ;
		if (indexes[1] < size - 1)
			solution_found = check_next_col(board, size, indexes, rules);
		else if (indexes[0] < size - 1)
			solution_found = check_next_row(board, size, indexes, rules);
		else
			return (1);
		if (solution_found)
			return (1);
	}
	board[indexes[0]][indexes[1]] = 0;
	return (0);
}

void	ft_print_board(int **board, int size)
{
	int		i;
	int		j;
	char	val;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			val = board[i][j] + 48;
			ft_putchar(val);
			if (j != size - 1)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

int	solution(int **board, int size, int **rules)
{
	int	indexes[2];

	indexes[0] = 0;
	indexes[1] = 0;
	if (ft_sky_scraper(board, size, indexes, rules))
		return (1);
	return (0);
}
