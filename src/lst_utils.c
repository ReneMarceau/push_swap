/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:05:05 by rmarceau          #+#    #+#             */
/*   Updated: 2023/05/29 02:02:50 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Creates a new doubly circular node
t_stack	*lstnew(int data, int index, int chunk)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = data;
	new_node->index = index;
	new_node->chunk = chunk;
	new_node->next = new_node;
	new_node->prev = new_node;
	return (new_node);
}

// Adds a doubly circular node on top the linked list
void	lstadd_front(t_stack **node_first, t_stack **node_last, t_stack *new)
{
	new->next = *node_first;
	new->prev = *node_last;
	*node_first = new;
	*node_last = new;
}

// Deletes a node from a linked list
void	delete_node(t_stack **node)
{
	t_stack	*tmp;

	if (*node)
	{
		tmp = *node;
		if (tmp->next != tmp)
		{
			*node = tmp->next;
			(*node)->prev = tmp->prev;
			tmp->prev->next = *node;
		}
		else
			*node = NULL;
		free(tmp);
	}
}
