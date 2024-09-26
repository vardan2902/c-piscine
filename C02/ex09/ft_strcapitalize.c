/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:10:43 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/08 21:34:44 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alphanumeric(char c)
{
	return ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'));
}

int	is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (is_upper(str[i]))
			str[i] += 32;
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	ft_strlowcase(str);
	i = 0;
	if (is_lower(str[i]))
		str[i] -= 32;
	while (str[++i])
		if (!is_alphanumeric(str[i - 1]) && is_lower(str[i]))
			str[i] -= 32;
	return (str);
}
