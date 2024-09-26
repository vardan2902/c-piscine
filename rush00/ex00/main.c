/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:40:35 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/07 16:22:29 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str);
void	rush(int x, int y);

int	is_all_digits(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}

int	ft_atoi(char *str)
{
	int	result;
	int	i;

	result = 0;
	i = -1;
	while (str[++i])
		result = result * 10 + (str[i] - 48);
	return (result);
}

int	check_args(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
	{
		ft_putstr("Please provide valid arguments\n\
x: positive integer\ny: positive integer\n");
		return (1);
	}
	if (!is_all_digits(argv[1]) || !is_all_digits(argv[2])
		|| argv[1][0] == '0' || argv[2][0] == '0')
	{
		ft_putstr("Arguments must be valid positive integers");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (check_args(argc, argv))
		return (0);
	rush(ft_atoi(argv[1]), ft_atoi(argv[2]));
	return (0);
}
