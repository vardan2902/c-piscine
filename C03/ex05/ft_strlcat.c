/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:22:40 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/10 20:37:10 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dest_len;
	unsigned int	src_len;

	i = -1;
	j = -1;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (!size || dest_len > size)
		return (dest_len + src_len);
	while (dest[++i])
		;
	while (src[++j] && j < size - dest_len - 1)
		dest[i++] = src[j];
	if (dest_len <= size)
		dest[i] = '\0';
	return (dest_len + src_len);
}
