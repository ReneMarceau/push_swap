/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:11:35 by rmarceau          #+#    #+#             */
/*   Updated: 2023/05/26 17:25:15 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Finds the smallest value among all unindexed nodes in the stack
static int	find_smallest(t_stack *stack)
{
	t_stack	*current;
	int	min;
	int	i;

	current = stack;
	min = INT_MAX;
	i = -1;
	while (++i < stack->size)
	{
		if (current->data < min && current->index == -1)
			min = current->data;
		current = current->next;
	}
	return (min);
}

// Sets the index value for each node in the stack based on their value and order
void set_index(t_stack *stack)
{
	t_stack *current;
	size_t	index;
	int		min;
	int		i;
	int		j;

	index = 0;
	i = 0;
	while (i++ < stack->size)
	{
		min = find_smallest(stack);
		current = stack;
		j = 0;
		while (j++ < stack->size)
		{
			if (current->data == min && current->index == -1)
				current->index = index++;
			current = current->next;
		}
	}
}

// Sets the chunk value for each node in the stack based on the chunk size
void    set_chunk(t_stack *stack, int chunk_size)
{
    int i;

    i = 0;
    while (i++ < stack->size)
    {
        stack->chunk = (stack->index / chunk_size);
        stack = stack->next;
    }
}

int	numberPerChunk(int total_numbers, int num_chunks)
{
	int	numbers_per_chunk;
	int	remaining_numbers;

	numbers_per_chunk = total_numbers / num_chunks;
	remaining_numbers = total_numbers % num_chunks;
	if (remaining_numbers > 0)
		numbers_per_chunk++;
	return (numbers_per_chunk);
}
