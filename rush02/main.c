/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:22:19 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/22 21:07:30 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	print_result(char *result)
{
	if (result)
	{
		ft_putstr(result);
		ft_putstr("\n");
	}
	else
		handle_error(DICT_ERROR);
}

int	handle_argument(char *dict, char *arg)
{
	char			*dict_content;
	t_dict_entry	*dictionary;
	char			*result;

	if (!is_valid_number(arg))
		return (handle_error(ARG_ERROR));
	dict_content = read_file_content(dict);
	if (!dict_content)
		return (handle_error(DICT_ERROR));
	dictionary = parse_dictionary(dict_content);
	if (!dictionary)
	{
		free(dict_content);
		return (handle_error(DICT_ERROR));
	}
	result = handle_large_number(&arg[get_num_pos(arg)], dictionary);
	print_result(result);
	free(dict_content);
	free(dictionary);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		return (handle_argument(DEFAULT_DICT, argv[1]));
	if (argc == 3)
		return (handle_argument(argv[1], argv[2]));
	return (handle_error(ARG_ERROR));
}
