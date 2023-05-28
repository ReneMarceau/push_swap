/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:05:05 by rmarceau          #+#    #+#             */
/*   Updated: 2023/05/28 18:29:11 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Creates a new doubly circular node
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
		if (!(tmp->value == tmp->next->value))
			*node = (*node)->next;
		else
			*node = NULL;
		free(tmp);
	}
}

//Fill The stack_a with all the value provided by quotes or arguments.
//But only if all the values are valids.
void	fill_stack(t_container *data, int argc, char **argv)
{
	int		len;

	if (argc == 2)
		data->tab = quotes_to_tab(argv, &data->size_a);
	else
		data->tab = args_to_tab(argc, argv, &data->size_a);
	if (!data->tab || !is_repeat(data->tab, data->size_a))
		end_program(data, true);
	if (is_sorted(data->tab, data->size_a))
	{
		end_program(data, false);
		exit(EXIT_SUCCESS);
	}
	len = data->size_a;
	while (--len >= 0)
	{
		if (!data->stack_a)
			data->stack_a = lstnew(data->tab[len], -1, -1);
		else
			lstadd_front(&data->stack_a, &data->stack_a->prev, lstnew(data->tab[len], -1, -1));
	}
	data->stack_a->prev->next = data->stack_a;
}
