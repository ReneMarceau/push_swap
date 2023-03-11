/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:05:05 by rmarceau          #+#    #+#             */
/*   Updated: 2023/03/11 15:23:26 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_stack	*lstnew(int data)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = new_node;
	new_node->prev = new_node;
	return (new_node);
}

void	lstadd_front(t_stack **node_first, t_stack **node_last, t_stack *new)
{
	new->next = *node_first;
	new->prev = *node_last;
	*node_first = new;
	*node_last = new;
}

t_stack	*fill_stack(char **args, int len)
{
	t_stack	*stack;

	stack = NULL;
	while (len >= 0)
	{
		if (!stack)
			stack = lstnew(ft_atoi(args[len]));
		else
			lstadd_front(&stack, &stack->prev, lstnew(ft_atoi(args[len])));
		len--;
	}
	return (stack);
}
