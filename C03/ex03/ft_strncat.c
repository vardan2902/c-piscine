/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:56:37 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/10 20:30:28 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	j = -1;
	while (dest[++i])
		;
	while (src[++j] && j < nb)
		dest[i++] = src[j];
	dest[i] = '\0';
	return (dest);
}
