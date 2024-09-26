/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:23:54 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/23 22:30:33 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	size;

	if (!begin_list || !(*begin_list))
		return (0);
	size = 0;
	while (*begin_list->next)
	{
		begin_list = begin_list->next;
		++size;
	}
	return (size);
}
