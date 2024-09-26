/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 00:13:00 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/22 20:43:28 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*get_scale_text(int len, int chunk_len, char *chunk_text,
	t_dict_entry *dictionary)
{
	char	*scale_str;
	char	*result;
	int		i;
	int		scale_digits;
	char	*combined_result;

	i = 0;
	scale_digits = len - (chunk_len - 1);
	scale_str = (char *)malloc((scale_digits + 1) * sizeof (char));
	if (!scale_str)
		return (NULL);
	scale_str[0] = '1';
	while (++i < scale_digits)
		scale_str[i] = '0';
	scale_str[scale_digits] = '\0';
	result = lookup_number_in_dict(scale_str, dictionary);
	free(scale_str);
	if (!result)
		return (NULL);
	combined_result = combine_strings(chunk_text, result);
	free(result);
	return (combined_result);
}

char	*process_remaining(char *result, int chunk_len,
	char *number, t_dict_entry *dictionary)
{
	char	*remaining_part;
	char	*remaining_text;
	char	*final_result;

	remaining_part = number + chunk_len;
	if (is_all_zeros(remaining_part))
		return (result);
	remaining_text = handle_large_number(remaining_part, dictionary);
	if (remaining_text)
	{
		final_result = combine_strings(result, remaining_text);
		free(result);
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

char	*process_large(int len, char *number, t_dict_entry *dictionary)
{
	int		chunk_len;
	char	chunk[4];
	char	*chunk_text;
	char	*result;

	chunk_len = get_chunk_len(len);
	ft_strncpy(chunk, number, chunk_len);
	chunk[chunk_len] = '\0';
	result = NULL;
	if (chunk_len == 3)
		chunk_text = process_number_hundreds(chunk, dictionary);
	else
		chunk_text = convert_number_to_text(chunk, dictionary);
	if (!chunk_text)
		return (NULL);
	result = get_scale_text(len, chunk_len, chunk_text, dictionary);
	free(chunk_text);
	if (!result)
		return (NULL);
	return (process_remaining(result, chunk_len, number, dictionary));
}

char	*handle_large_number(char *number, t_dict_entry *dictionary)
{
	int		len;
	char	*result;

	result = NULL;
	len = ft_strlen(number);
	if (len > 3)
		result = process_large(len, number, dictionary);
	else if (len == 3)
		result = process_number_hundreds(number, dictionary);
	else if (len <= 2)
		result = convert_number_to_text(number, dictionary);
	return (result);
}
