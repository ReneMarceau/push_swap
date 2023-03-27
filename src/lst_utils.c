/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:05:05 by rmarceau          #+#    #+#             */
/*   Updated: 2023/03/27 18:38:45 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Creates a new doubly circular node
t_stack	*lstnew(int data)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = new_node;
	new_node->prev = new_node;
	return (new_node);
}

//Adds a doubly circular node on top the linked list
void	lstadd_front(t_stack **node_first, t_stack **node_last, t_stack *new)
{
	new->next = *node_first;
	new->prev = *node_last;
	*node_first = new;
	*node_last = new;
}

//Deletes a node from a linked list
void	delete_node(t_stack **node)
{
	t_stack	*tmp;

	if (*node)
	{
		tmp = *node;
		free(*node);
		if (!(tmp->data == tmp->next->data))
			*node = tmp->next;
		else
			*node = NULL;
	}
}

//Fill The stack_a with all the value provided by quotes or arguments.
//But only if all the values are valids.
t_stack	*fill_stack(int argc, char **argv, int *size)
{
	t_stack	*stack;
	int		*tab;
	int		len;

	if (argc == 2)
		tab = quotes_to_tab(argv, &size);
	else
		tab = args_to_tab(argc, argv, &size);
	if (!tab || !is_repeat(tab, *size))
	{
		free(tab);
		return (NULL);
	}
	if (is_sorted(tab, *size))
	{
		free(tab);
		exit(EXIT_SUCCESS);
	}
	len = *size;
	while (--len >= 0)
	{
		if (!stack)
			stack = lstnew(tab[len]);
		else
			lstadd_front(&stack, &stack->prev, lstnew(tab[len]));
	}
	free(tab);
	return (stack);
}
