/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:47:16 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/24 22:51:43 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
	int (*cmpf)(void *, void *))
{
	t_btree	*found_left;
	t_btree	*found_right;

	if (!root || !cmpf)
		return (NULL);
	found_left = (t_btree *)btree_search_item(root->left, data_ref, cmpf);
	if (found_left)
		return (found_left);
	if (!cmpf(root->item, data_ref))
		return (root);
	found_right = (t_btree *)btree_search_item(root->right, data_ref, cmpf);
	if (found_right)
		return (found_right);
	return (NULL);
}
