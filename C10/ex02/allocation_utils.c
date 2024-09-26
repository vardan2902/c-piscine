/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 01:12:49 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/23 01:52:29 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	s = (const char *)src;
	d = (char *)dest;
	if (!dest || !src)
		return (NULL);
	i = -1;
	while (++i < n)
		d[i] = s[i];
	return (dest);
}

void	*ft_realloc(void *ptr, size_t original_size, size_t new_size)
{
	void	*new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		return (malloc(new_size));
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	if (original_size > 0 && ptr != NULL)
	{
		if (original_size < new_size)
			ft_memcpy(new_ptr, ptr, original_size);
		else
			ft_memcpy(new_ptr, ptr, new_size);
	}
	free(ptr);
	return (new_ptr);
}
