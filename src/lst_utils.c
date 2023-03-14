/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:05:05 by rmarceau          #+#    #+#             */
/*   Updated: 2023/03/13 21:20:32 by rmarceau         ###   ########.fr       */
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

t_stack	*fill_stack(int argc, char **argv)
{
	t_stack	*stack;
	int		*tab;
	int		len;

	stack = NULL;
	if (argc == 2)
		tab = quotes_to_tab(argv);
	else
		tab = args_to_tab(argc, argv);
	if (!tab || !is_repeat(tab))
		return (NULL);
	if (is_sorted(tab))
		exit(EXIT_SUCCESS);
	// count_arg compte mal si il y a un 0
	len = (count_arg(tab));
	ft_printf("len: %d\n", len);
	while (--len >= 0)
	{
		if (!stack)
			stack = lstnew(tab[len]);
		else
			lstadd_front(&stack, &stack->prev, lstnew(tab[len]));
	}
	return (stack);
}
