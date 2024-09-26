/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:42:56 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/22 20:45:47 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*process_hundred(char *number, t_dict_entry *dictionary)
{
	char	*hundred_text;
	char	*result;
	char	first_digit[2];
	char	*first_digit_text;

	first_digit[0] = number[0];
	first_digit[1] = '\0';
	result = NULL;
	first_digit_text = convert_number_to_text(first_digit, dictionary);
	if (!first_digit_text)
		return (NULL);
	hundred_text = lookup_number_in_dict("100", dictionary);
	if (hundred_text)
		result = combine_strings(first_digit_text, hundred_text);
	free(first_digit_text);
	return (result);
}

char	*process_tens_and_ones(char *result, char *number,
	t_dict_entry *dictionary)
{
	char	*remaining_text;
	char	*final_result;

	if (number[1] != '0')
		number += 1;
	else
		number += 2;
	remaining_text = convert_number_to_text(number, dictionary);
	if (remaining_text)
	{
		if (result)
			final_result = combine_strings(result, remaining_text);
		if (result)
			free(result);
		else
			final_result = ft_strdup(remaining_text);
		free(remaining_text);
		result = final_result;
	}
	else
	{
		free(result);
		return (NULL);
	}
	return (result);
}

char	*process_number_hundreds(char *number, t_dict_entry *dictionary)
{
	char	*result;

	result = NULL;
	if (number[0] != '0')
		result = process_hundred(number, dictionary);
	if (number[1] != '0' || number[2] != '0')
		result = process_tens_and_ones(result, number, dictionary);
	if (number[0] == '0' && number[1] == '0' && number[2] == '0')
		result = ft_strdup("");
	return (result);
}

int	is_all_zeros(char *str)
{
	while (*str)
	{
		if (*str != '0')
			return (0);
		str++;
	}
	return (1);
}

int	get_chunk_len(int len)
{
	if (len % 3 == 0)
		return (3);
	return (len % 3);
}
