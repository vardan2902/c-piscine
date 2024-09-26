/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:56:15 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/24 22:46:21 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_list	*new_list_node(t_btree *node, int level)
{
	t_list	*list_node;

	list_node = (t_list *)malloc(sizeof (t_list));
	if (!list_node)
		return (NULL);
	list_node->node = node;
	list_node->next = NULL;
	list_node->lvl = level;
	return (list_node);
}

void	enqueue(t_list **front, t_list **rear, t_btree *node, int level)
{
	t_list	*q_node;

	q_node = new_list_node(node, level);
	if (!*rear)
	{
		*front = q_node;
		*rear = q_node;
	}
	else
	{
		(*rear)->next = q_node;
		*rear = q_node;
	}
}

t_list	*dequeue(t_list **front, t_list **rear)
{
	t_list	*temp;

	if (!*front)
		return (NULL);
	temp = *front;
	*front = (*front)->next;
	if (!*front)
		*rear = NULL;
	return (temp);
}

void	process_node(t_list **front, t_list **rear,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_list	*curr_list_node;
	t_btree	*curr_node;
	int		current_level;
	int		is_first_elem;

	curr_list_node = dequeue(front, rear);
	if (!curr_list_node)
		return ;
	curr_node = curr_list_node->node;
	current_level = curr_list_node->lvl;
	if (!(*front) || (*front)->lvl != current_level)
		is_first_elem = 1;
	else
		is_first_elem = 0;
	applyf(curr_node->item, current_level, is_first_elem);
	if (curr_node->left)
		enqueue(front, rear, curr_node->left, current_level + 1);
	if (curr_node->right)
		enqueue(front, rear, curr_node->right, current_level + 1);
	free(curr_list_node);
}

void	btree_apply_by_level(t_btree *root,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_list	*front;
	t_list	*rear;

	front = NULL;
	rear = NULL;
	if (!root)
		return ;
	enqueue(&front, &rear, root, 0);
	while (front)
		process_node(&front, &rear, applyf);
}
