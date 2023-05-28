/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:11:35 by rmarceau          #+#    #+#             */
/*   Updated: 2023/05/28 15:35:13 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Finds the smallest value among all unindexed nodes in the stack
static int	find_smallest(t_stack *stack, int size)
{
	t_stack	*current;
	int	min;
	int	i;

	current = stack;
	min = INT_MAX;
	i = 0;
	while (i++ < size)
	{
		if (current->value < min && current->index == -1)
			min = current->value;
		current = current->next;
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
		current = stack;
		j = 0;
		while (j++ < size)
		{
			if (current->value == min && current->index == -1)
				current->index = index++;
			current = current->next;
		}
	}
}

// Sets the chunk value for each node in the stack based on the chunk size
void    set_chunk(t_container *data, int chunk_size)
{
	t_stack *current;
    int i;

	current = data->stack_a;
    i = 0;
    while (i++ < data->size_a)
	{
		current->chunk = (current->index / chunk_size);
		current = current->next;
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
