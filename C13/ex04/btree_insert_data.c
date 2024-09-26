/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:35:43 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/24 23:13:54 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
	int (*cmpf)(void *, void *))
{
	int	cmp_result;

	if (!root)
		return ;
	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	cmp_result = cmpf((*root)->item, item);
	if (!cmp_result)
		return ;
	if (cmp_result > 0)
		btree_insert_data(&(*root)->left, item, cmpf);
	else
		btree_insert_data(&(*root)->right, item, cmpf);
}
