/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:40:25 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/22 20:43:51 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*lookup_number_in_dict(char *number, t_dict_entry *dictionary)
{
	int	i;

	i = 0;
	while (dictionary[i].number != NULL)
	{
		if (ft_strcmp(dictionary[i].number, number) == 0)
			return (dictionary[i].text);
		i++;
	}
	return (NULL);
}

char	*convert_simple_tens(char *number, t_dict_entry *dictionary)
{
	char	*text;

	text = lookup_number_in_dict(number, dictionary);
	if (!text)
		return (NULL);
	return (ft_strdup(text));
}

char	*convert_two_digit_tens(char *result, t_dict_entry *dictionary,
	char *ones)
{
	char	*ones_text;
	char	*combined_result;

	ones_text = lookup_number_in_dict(ones, dictionary);
	if (ones_text)
	{
		combined_result = combine_strings(result, ones_text);
		return (combined_result);
	}
	else
		return (NULL);
}

char	*convert_general_tens(char *result, t_dict_entry *dictionary, int num)
{
	char	*tens;
	char	*ones;
	char	*tens_text;

	tens = ft_itoa((num / 10) * 10);
	ones = ft_itoa(num % 10);
	tens_text = lookup_number_in_dict(tens, dictionary);
	if (tens_text)
		result = ft_strdup(tens_text);
	else
	{
		free(tens);
		free(ones);
		return (NULL);
	}
	if (num % 10 != 0)
		result = convert_two_digit_tens(result, dictionary, ones);
	free(tens);
	free(ones);
	return (result);
}

char	*convert_number_to_text(char *number, t_dict_entry *dictionary)
{
	int		num;
	int		i;
	char	*result;

	i = -1;
	num = 0;
	while (number[++i])
		num = num * 10 + (number[i] - '0');
	result = NULL;
	if (num <= 20 || (num % 10 == 0 && num <= 90))
		return (convert_simple_tens(number, dictionary));
	else if (num > 20 && num <= 100)
		return (convert_general_tens(result, dictionary, num));
	return (result);
}
