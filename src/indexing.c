/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:11:35 by rmarceau          #+#    #+#             */
/*   Updated: 2023/05/18 18:15:05 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Finds the smallest value among all unindexed nodes in the stack
static int	find_smallest(t_stack *stack, int size)
{
	int	i;
	int	min;

	min = INT_MAX;
	i = -1;
	while (++i < size)
	{
		if (stack->data < min && stack->index == -1)
			min = stack->data;
		stack = stack->next;
	}
	return (min);
}

// Sets the index value for each node in the stack based on their value and order
void set_index(t_stack *stack, int size)
{
	t_stack *current;
	size_t	index;
	int		min;
	int		i;
	int		j;

	index = 0;
	i = 0;
	while (i++ < size)
	{
		min = find_smallest(stack, size);
		j = 0;
		current = stack;
		while (j++ < size)
		{
			if (current->data == min && current->index == -1)
				current->index = index++;
			current = current->next;
		}
	}
}

// Sets the chunk value for each node in the stack based on the chunk size
void    set_chunk(t_stack *stack, int size, int chunk_size)
{
    int i;

    i = 0;
    while (i++ < size)
    {
        stack->chunk = (stack->index / chunk_size);
        stack = stack->next;
    }
}
